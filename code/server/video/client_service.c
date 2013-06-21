

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

#include "client_service.h"

struct _ClientService
{
    int port;
    int listen_socket;
    VideoServer *video_server;
};

typedef struct _ClientThreadArg
{
    int connect_socket;
    VideoServer *video_server;
}ClientThreadArg;

typedef struct _SendBuffer
{
    void *buf;
    int buf_size;
}SendBuffer;

static void request_stream(unsigned char *buf, int buf_size, void *ctx)
{
    SendBuffer *send_buffer = (SendBuffer *)ctx;
    
    send_buffer->buf_size = buf_size;
    memcpy(send_buffer->buf, buf, buf_size);
}

static void *client_thread(void *arg)
{
    int type = 1;
    int connect_socket = ((ClientThreadArg *)arg)->connect_socket;
    VideoServer *video_server = ((ClientThreadArg *)arg)->video_server;
    SendBuffer send_buffer;
    send_buffer.buf = malloc(CONTAINER_SIZE);

    pthread_detach(pthread_self());

    for (;;)
    {
        if (video_server_req_stream(video_server, 0, request_stream, &send_buffer) == -1)
        {
            break;
        }

        if (send(connect_socket, (void *)&type, sizeof(int), 0) <= 0)
        {
            break;
        }

        if (send(connect_socket, (void *)&send_buffer.buf_size, sizeof(int), 0) <= 0)
        {
            break;
        }

        if (send(connect_socket, (void *)send_buffer.buf, send_buffer.buf_size, 0) <= 0)
        {
            break;
        }
    }

    printf("client [socket:%d] exited\n", connect_socket);
    close(connect_socket);
    free(send_buffer.buf);
    pthread_exit(NULL);
}

ClientService *client_service_new(int port, VideoServer *video_server)
{
    ClientService *thiz = (ClientService *)malloc(sizeof(ClientService));

    if (thiz != NULL)
    {
        thiz->port = port;
        thiz->video_server = video_server;
    }

    return thiz;
}

void client_service_destroy(ClientService *thiz)
{
    if (thiz != NULL)
    {
        free(thiz);
    }
}

void client_service_run(ClientService *thiz)
{
    struct sockaddr_in serv_addr;
    struct sockaddr_in disp_addr;
    struct sockaddr_in client_addr;
    socklen_t disp_addr_len;
    socklen_t client_addr_len;
    int connect_socket;
    int listen_socket;
    int reuse;
    pthread_t client_tid;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    thiz->listen_socket = listen_socket;

    reuse = 1;
    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) == -1)
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(thiz->port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) ==-1)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, BACKLOG) == -1)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    disp_addr_len = sizeof(disp_addr);
    if (getsockname(listen_socket, (struct sockaddr *)&disp_addr, &disp_addr_len) == -1)
    {
        perror("getsockname failed");
        exit(EXIT_FAILURE);
    }
    char disp_addr_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &disp_addr.sin_addr, disp_addr_str, INET_ADDRSTRLEN);
    printf("master server is listening at %s:%d\n", disp_addr_str, ntohs(disp_addr.sin_port));

    ClientThreadArg arg;
    for (;;)
    {
        client_addr_len = sizeof(client_addr);
        if ((connect_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
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
        printf("client(%s) [socket:%d] is connected\n", disp_addr_str, connect_socket);

        arg.connect_socket = connect_socket;
        arg.video_server = thiz->video_server;
        pthread_create(&client_tid, NULL, client_thread, &arg);
    }
}

void client_service_stop(ClientService *thiz)
{
    assert(thiz != NULL);    

    close(thiz->listen_socket);
}

