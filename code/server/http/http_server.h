/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/04/08
 */

#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "i_http_request_handler.h"
#include "http_method.h"
#include "http_response.h"
#include "http_request.h"
#include "utils_log.h"

#include <map>
#include <errno.h>

using namespace std;


#define HTTP_MAX_DATA_BLOCK_SIZE 4096
#define HTTP_MAX_HEADER_LINE_SIZE 1024

class HttpServer {
    
    public:
        HttpServer();
        ~HttpServer();
        void AddHandler(IHttpRequestHandler* handler) { handlers_list_[handler->method()] = handler; }

        map<HttpMethod, IHttpRequestHandler*> handlers_list() { return handlers_list_; }
        void Listen(int port);

        int Receive(HttpRequest& request, int client_sockfd);
        int Answer(HttpResponse response, int client_sockfd);

        int handle_request(HttpRequest request, int client_socket_fd);

        void LoopAccepting(int server_sockfd);
        static void* client_thread_func(void* ptr_this);
        int current_client_sockfd() { return current_client_sockfd_; }

    private:
        int port_;
        int current_client_sockfd_;
        int server_sockfd_;
        map<HttpMethod, IHttpRequestHandler*> handlers_list_;
};

#endif
