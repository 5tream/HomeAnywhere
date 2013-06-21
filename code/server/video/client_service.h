/**
 * @File: client_service.h
 * @Author: Joe Shang (shangchuanren@gmail.com)
 * @Brief: Thread for client service.
 */

#ifndef _CLIENT_SERVICE_H_
#define _CLIENT_SERVICE_H_

#include "typedef.h"
#include "video_server.h"

DECLS_BEGIN

struct _ClientService;
typedef struct _ClientService ClientService;

ClientService *client_service_new(int port, VideoServer *video_server);
void client_service_destroy(ClientService *thiz);
void client_service_run(ClientService *thiz);
void client_service_stop(ClientService *thiz);

DECLS_END

#endif
