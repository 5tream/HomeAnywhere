/**
 * @File: video_server.h
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: Video server module.
 */

#ifndef _VIDEO_SERVER_H_
#define _VIDEO_SERVER_H_

#include "typedef.h"

DECLS_BEGIN

struct _VideoServer;
typedef struct _VideoServer VideoServer;

VideoServer *video_server_new(int port, int stream_count);
void video_server_destroy(VideoServer *thiz);
void video_server_run(VideoServer *thiz);
void video_server_stop(VideoServer *thiz);
int video_server_get_id_by_ctx(VideoServer *thiz, CtxCompareFunc compare, void *ctx);
void video_server_req_stream(VideoServer *thiz, int stream_id, DataRequestFunc request, void *ctx);

DECLS_END

#endif
