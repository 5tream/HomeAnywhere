/**
 * File: video_container.h
 * Author: Joe Shang (shangchuanren@gmail.com)
 * Brief: The video data container with processed format.
 */

#ifndef _VIDEO_CONTAINER_H_
#define _VIDEO_CONTAINER_H_

#include <pthread.h>
#include "typedef.h"

DECLS_BEGIN

typedef struct _VideoContainer
{
    int buf_capacity;
    
    int processed_size;
    unsigned char *processed_buffer;

    pthread_mutex_t db;
    pthread_cond_t  db_update;
}VideoContainer;

VideoContainer *video_container_new(int buf_capacity);
void video_container_updatedb(VideoContainer *thiz,
                              void *in_buffer,
                              int in_size,
                              int in_format,
                              FrameProcessFunc frame_process,
                              int out_format);
void video_container_requestdb(VideoContainer *thiz,
                               DataRequestFunc requestdb_callback,
                               void *ctx);
void video_container_releasedb(VideoContainer *thiz);
void video_container_destroy(VideoContainer *thiz);

DECLS_END

#endif
