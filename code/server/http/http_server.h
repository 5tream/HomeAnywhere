/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/04/08
 */

#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "i_http_request_handler.h"
#include "i_http_method.h"
#include "http_response.h"
#include "http_request.h"

#include <map.h>

using namespace std;

#ifdef __TIME_STAMP
#define TIME_STAMP "["__DATE__"]["__TIME__"]
#else
#define TIME_STAMP "
#endif

#ifdef __DEBUG
#define DEBUG(format,...) printf(TIME_STAMP[DEBUG ==> File: "__FILE__" Line:%5d] \n"format"\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(format)
#endif

#ifdef __INFO
#define INFO(format,...) printf(TIME_STAMP[INFO  ==> File: "__FILE__" Line: %5d] \n"format"\n", __LINE__, ##__VA_ARGS__)
#else
#define INFO(format)
#endif

#ifdef __ERROR
#define ERROR(format,...) printf(TIME_STAMP[ERROR ==> File: "__FILE__" Line: %5d] \n"format"\n", __LINE__, ##__VA_ARGS__)
#else
#define ERROR(format)
#endif

#ifdef __FATAL
#define FATAL(format,...) sprintf(stderr, TIME_STAMP[FATAL==> File: "__FILE__" Line: %5d] \n%s\n"format"\n", __LINE__, strerror(errno), ##__VA_ARGS__)
#else
#define FATAL(format)
#endif

#define HTTP_MAX_DATA_BLOCK_SIZE 4096
#define HTTP_MAX_HEADER_LINE_SIZE 1024

class HttpServer {
    
    public:
        HttpServer();
        ~HttpServer();
        void AddHandler(IHttpRequestHandler handler) { handlers_list_[handler->method()] = handler; }
        void Listen(int port);

    private:
        void DecodeRequest(HttpRequest request, char* raw_data);
        void EncodeResponse(HttpResponse response, char* raw_data);

        int handle_request(HttpRequest request, int client_socket_fd);

    private:
        int port_;
        int server_sockfd_;
        map<IHttpMethod, IHttpRequestHandler> handlers_list_;
}

#endif
