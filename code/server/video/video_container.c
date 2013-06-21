/**
 * File: video_container.c
 * Author: Joe Shang (shangchuanren@gmail.com)
 * Brief: The video data container with processed format.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "video_container.h"

VideoContainer *video_container_new(int buf_capacity)
{
    VideoContainer *thiz = (VideoContainer *)malloc(sizeof(VideoContainer));
    
    if (thiz != NULL)
    {
        thiz->buf_capacity = buf_capacity; 

        thiz->processed_size = 0;
        thiz->processed_buffer = (unsigned char *)malloc(buf_capacity);
        if (thiz->processed_buffer == NULL)
        {
            return NULL;
        }

        pthread_mutex_init(&thiz->db, NULL);
        pthread_cond_init(&thiz->db_update, NULL);
    }

    return thiz;
}

void video_container_updatedb(VideoContainer *thiz,
                              void *in_buffer,
                              int in_size,
                              int in_format,
                              FrameProcessFunc frame_process,
                              int out_format)
{
    assert(thiz != NULL && frame_process != NULL);

    pthread_mutex_lock(&thiz->db);

    thiz->processed_size = frame_process(thiz->processed_buffer, 
                                         (unsigned char *)in_buffer,
                                         in_size,
                                         in_format,
                                         out_format);

    pthread_cond_broadcast(&thiz->db_update);
    pthread_mutex_unlock(&thiz->db);
}

void video_container_requestdb(VideoContainer *thiz,
                               DataRequestFunc requestdb_callback,
                               void *ctx)
{
    assert(thiz != NULL);

    /* wait for new frame coming after updatedb */
    pthread_mutex_lock(&thiz->db);
    pthread_cond_wait(&thiz->db_update, &thiz->db);

    if (thiz->processed_buffer != NULL)
    {
        requestdb_callback(thiz->processed_buffer, thiz->processed_size, ctx);
    }

    pthread_mutex_unlock(&thiz->db);
}

void video_container_releasedb(VideoContainer *thiz)
{
    pthread_mutex_unlock(&thiz->db);
}

void video_container_destroy(VideoContainer *thiz)
{
    assert(thiz != NULL);

    if (thiz->processed_buffer != NULL)
    {
        free(thiz->processed_buffer);
    }
    thiz->processed_buffer = NULL;

    pthread_cond_broadcast(&thiz->db_update);
    pthread_cond_destroy(&thiz->db_update);
    pthread_mutex_unlock(&thiz->db);
    pthread_mutex_destroy(&thiz->db);

    free(thiz);
}
