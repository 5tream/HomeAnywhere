/* Copyright (C) 
 * 2013 - Rye Yao
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */
/**
 * @file http_server.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
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
