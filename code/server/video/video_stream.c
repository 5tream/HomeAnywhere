/**
 * @File: video_stream.c
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: stream module.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>

#include "utils_log.h"
#include "video_stream.h"

#define BUF_SIZE 4096

static int frame_process(unsigned char *out_buf,
                         unsigned char *in_buf,
                         int in_size,
                         int in_format,
                         int out_format)
{
    memcpy(out_buf, in_buf, in_size);
    return in_size;
}

static void stream_thread_cleanup(void *arg)
{
    Stream *stream = *(Stream **)arg;

    if (stream != NULL)
    {
        DEBUG("stream %d thread destroy\n", stream->id);

        video_container_destroy(stream->container);
        free(stream);
        *(Stream **)arg = NULL;
    }
}

void *video_stream_thread(void *user_data)
{
    int in_format = 0;
    int out_format = 0;
    int in_size = 0;
    unsigned char *in_buffer;

    int ctx;
    int pos;
    int left_size;
    int recv_size;
    int recv_buf_size;
    unsigned char recv_buf[BUF_SIZE];

    Stream *stream = *(Stream **)user_data;

    pthread_detach(pthread_self());
    pthread_cleanup_push(stream_thread_cleanup, user_data);

    for (;;)
    {
        /* extract video data and related stream context from socket */
        /* 1. receive stream context */
        recv(stream->socket, (void *)&ctx, sizeof(int), 0);
        stream->ctx = (void *)ctx;
        //DEBUG("stream %d receive stream context %d\n", stream->id, ctx);

        /* 2. receive frame size */
        recv(stream->socket, (void *)&in_size, sizeof(int), 0);
        //DEBUG("stream %d receive frame size %d\n", stream->id, in_size);
        if (in_size < 0)
        {
            continue;
        }
        in_buffer = (unsigned char *)malloc(in_size);

        pos = 0;
        left_size = in_size;
        recv_buf_size = BUF_SIZE;
        while (left_size > 0)
        {
            if (left_size < BUF_SIZE)
            {
                recv_buf_size = left_size;
            }

            if ((recv_size = recv(stream->socket, recv_buf, recv_buf_size, 0)) == 0)
            {
                DEBUG("stream %d exited\n", stream->id);

                free(in_buffer);
                in_buffer = NULL;
                pthread_exit(NULL);
            }

            memcpy(in_buffer + pos, recv_buf, recv_size);

            left_size -= recv_size;
            pos += recv_size;
        }

        //DEBUG("stream %d receive frame finished\n", stream->id);

        /* update container's content */
        video_container_updatedb(stream->container,
                                 in_buffer,
                                 in_size,
                                 in_format,
                                 frame_process,
                                 out_format);

        free(in_buffer);
        in_buffer = NULL;
    }

    pthread_cleanup_pop(1);

    return NULL;
}
