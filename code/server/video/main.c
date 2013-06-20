/**
 * @File: main.c
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: The main program of video server.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "video_server.h"

#define STREAM_COUNT        10

pthread_t video_server_tid;

static void video_server_cleanup(void *arg)
{
    VideoServer *video_server = (VideoServer *)arg;

    video_server_stop(video_server);
    video_server_destroy(video_server);
}

static void *video_server_thread(void *arg)
{
    VideoServer *video_server = (VideoServer *)arg;

    pthread_cleanup_push(video_server_cleanup, arg);

    video_server_run(video_server);

    pthread_cleanup_pop(1);

    return NULL;
}

static void signal_handler(int sig_num)
{
    void *tret;

    pthread_cancel(video_server_tid);
    pthread_join(video_server_tid, &tret);

    exit(0);
}

int main(int argc, char *argv[])
{
    VideoServer *video_server;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s stream_port client_port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);
    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        fprintf(stderr, "can not register signal handler\n");
        exit(EXIT_FAILURE);
    }

    video_server = video_server_new(atoi(argv[1]), STREAM_COUNT); 
    pthread_create(&video_server_tid, NULL, video_server_thread, (void *)video_server);

    for (;;)
    {
    }

    return 0;
}
