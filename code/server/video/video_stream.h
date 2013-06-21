/**
 * @File: video_stream.h
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: stream module.
 */

#ifndef _VIDEO_STREAM_H_
#define _VIDEO_STREAM_H_

#include "typedef.h"
#include "video_container.h"

DECLS_BEGIN

typedef struct _Stream
{
    int id;
    void *ctx;
    int socket;
    pthread_t thread_id;
    VideoContainer *container;
}Stream;

void *video_stream_thread(void *user_data);

DECLS_END

#endif
