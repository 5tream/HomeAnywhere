/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/04/08
 */

#ifndef SERVER_H
#define SERVER_H

#include "HttpMessage.h"
#define SRVR_LOG(arg) printf("[SERVER] %s", arg)

#define HTTP_MAX_DATA_BLOCK_SIZE 4096
#define HTTP_MAX_HEADER_LINE_SIZE 1024

class Server {
    
    public:
        void AddHandler(Method, HttpHandler);
        void Listen(int);

    private:
        void DecodeRequest(HttpRequest, char*);
        void EncodeResponse(HttpResponse, char*);

        int handle_request(HttpRequest, int);

    private:
        int port;
}

#endif
