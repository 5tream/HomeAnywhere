/**
 * @File: main.c
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: The main program of video server.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "video_server.h"

#define STREAM_COUNT        10

VideoServer *video_server;

static void signal_handler(int sig_num)
{
    video_server_stop(video_server);
    video_server_destroy(video_server);

    exit(0);
}

int main(int argc, char *argv[])
{
    int port;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGPIPE, SIG_IGN);
    if (signal(SIGINT, signal_handler) == SIG_ERR)
    {
        fprintf(stderr, "can not register signal handler\n");
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);
    video_server = video_server_new(port, STREAM_COUNT); 
    video_server_run(video_server);

    return 0;
}
