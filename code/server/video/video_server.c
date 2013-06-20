/**
 * @File: video_server.c
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: Video server module.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "utils_log.h"
#include "video_server.h"
#include "video_stream.h"
#include "video_container.h"

#define BACKLOG         10
#define CONTAINER_SIZE  320 * 240 * 2

struct _VideoServer
{
    int port;
    int stream_count;
    int stream_cur_max;
    int listen_socket;
    Stream **stream_list;
};

static int video_server_find_avail_index(VideoServer *thiz)
{
    int i;
    for (i = 0; i < thiz->stream_count; i++)
    {
        if (thiz->stream_list[i] == NULL)
        {
            return i;
        }
    }

    return -1;
}

VideoServer *video_server_new(int port, int stream_count)
{
    int i;
    VideoServer *thiz = malloc(sizeof(VideoServer));

    if (thiz != NULL)
    {
        thiz->port = port;
        thiz->stream_count = stream_count;
        thiz->stream_cur_max = 0;
        thiz->stream_list = malloc(sizeof(Stream *) * stream_count);
        if (thiz->stream_list == NULL)
        {
            return NULL;
        }
        
        for (i = 0; i < stream_count; i++)
        {
            thiz->stream_list[i] = NULL;
        }

        DEBUG("video server new finished\n");
    }

    return thiz;
}

void video_server_destroy(VideoServer *thiz)
{
    int i;

    DEBUG("video server begin to destroy\n");

    if (thiz->stream_list)
    {
        for (i = 0; i < thiz->stream_count; i++)
        {
            if (i > thiz->stream_cur_max)
            {
                break;
            }

            if (thiz->stream_list[i] != NULL)
            {
                DEBUG("video server destroy stream %d\n", i);
                video_container_destroy(thiz->stream_list[i]->container);
                free(thiz->stream_list[i]);
            }
        }
        free(thiz->stream_list);
    }
    thiz->stream_list = NULL;

    free(thiz);
}

void video_server_run(VideoServer *thiz)
{
    struct sockaddr_in serv_addr;
    struct sockaddr_in disp_addr;
    struct sockaddr_in client_addr;
    socklen_t disp_addr_len;
    socklen_t client_addr_len;
    int connect_socket;

    thiz->listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (thiz->listen_socket == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(thiz->port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(thiz->listen_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(thiz->listen_socket, BACKLOG) == -1)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    disp_addr_len = sizeof(disp_addr);
    if (getsockname(thiz->listen_socket, (struct sockaddr *)&disp_addr, &disp_addr_len) == -1)
    {
        perror("getsockname failed");
        exit(EXIT_FAILURE);
    }
    char disp_addr_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &disp_addr.sin_addr, disp_addr_str, INET_ADDRSTRLEN);
    printf("server is listening at %s:%d\n", disp_addr_str, ntohs(disp_addr.sin_port));

    int index;
    for (;;)
    {
        client_addr_len = sizeof(client_addr);
        if ((connect_socket = accept(thiz->listen_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
        {
            if (errno == EINTR)
            {
                continue;
            }
            else
            {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
        }
        inet_ntop(AF_INET, &client_addr.sin_addr, disp_addr_str, INET_ADDRSTRLEN);
        printf("client(%s) is connected\n", disp_addr_str);
        
        index = video_server_find_avail_index(thiz);
        if (index != -1)
        {
            if (index > thiz->stream_cur_max)
            {
                thiz->stream_cur_max = index;
            }

            thiz->stream_list[index] = malloc(sizeof(Stream));
            thiz->stream_list[index]->id = index;
            thiz->stream_list[index]->ctx = NULL;
            thiz->stream_list[index]->socket = connect_socket;
            thiz->stream_list[index]->container = video_container_new(CONTAINER_SIZE);

            DEBUG("video stream %d created\n", index);

            pthread_create(&thiz->stream_list[index]->thread_id, 
                           NULL, 
                           video_stream_thread, 
                           (void *)&thiz->stream_list[index]);
        }
        else
        {
            fprintf(stderr, "no room for connection\n");
            close(connect_socket);
        }
    }
}

void video_server_stop(VideoServer *thiz)
{
    close(thiz->listen_socket);

    DEBUG("video server stop\n");
}

int video_server_get_id_by_ctx(VideoServer *thiz, CtxCompareFunc compare, void *ctx)
{
    int i = -1;

    for (i = 0; i < thiz->stream_cur_max; i++)
    {
        if (compare(ctx, thiz->stream_list[i]->ctx) == 0)
        {
            break;
        }
    }

    return i;
}

void video_server_req_stream(VideoServer *thiz, int stream_id, DataRequestFunc request, void *ctx)
{
    assert(stream_id >= 0 && stream_id <= thiz->stream_cur_max);

    video_container_requestdb(thiz->stream_list[stream_id]->container, request, ctx); 
}

