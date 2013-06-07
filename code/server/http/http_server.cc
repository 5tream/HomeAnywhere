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
 * @file http_server.cc
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#include "http_server.h"
#include "http_header_items.h"
#include "http_parser.h"
#include "utils_log.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>

#define HTTP_MESSAGE_MAX_LEN 80*1024
#define BACKLOG 10

void* HttpServer::client_thread_func (void* ptr_this) {

    bool close_on_finished = true;

    INFO("A client has connected.\n");

    HttpServer* http_server = (HttpServer*) ptr_this;
    int client_sockfd = http_server->current_client_sockfd();

    pthread_detach(pthread_self());

    while(true) {

        HttpRequest request;
        HttpResponse response;

        // Parse request
        DEBUG("Parse request\n");
        if (http_server->Receive(request, client_sockfd) < 0 ) {
            ERROR("Receive request error.\n");
            close_on_finished = true;
        }

        // Handle request
        DEBUG("Handle request\n");
        IHttpRequestHandler* handler = http_server->handlers_list()[request.method()];

        DEBUG("request handler got for %s\n", GetStringFromMethod(handler->method()).c_str());
        assert(handler != NULL);

        if (handler->Handle(request, response) != 0) {
            ERROR("handle request");
            close_on_finished = true;
        }

        // Send response
        DEBUG("Send response\n");
        if (http_server->Answer(response, client_sockfd) < 0) {
            ERROR("Answer request error.\n");
            close_on_finished = true;
        }

        if (!strcmp(response.headers()[HH_KEEP_ALIVE].c_str(), "true")) {
            close_on_finished = false;
        }

        if (close_on_finished) {
            break;
        }
    }

    close(client_sockfd);
    pthread_exit(NULL);
}

HttpServer::HttpServer()
{
    if ((server_sockfd_ = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        FATAL("server_sockfd");
        exit(0);
    }
}

HttpServer::~HttpServer() {
    
}

void HttpServer::Listen(int port)
{
    port_ = port;

    struct sockaddr_in server_addr, temp_addr;
    socklen_t temp_len;

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_);

    if (bind(server_sockfd_, 
             (struct sockaddr *) &server_addr,
             sizeof(server_addr)) == -1) {

        FATAL("bind");
        exit(1);
    }

    temp_len = sizeof(struct sockaddr);
    if (getsockname(server_sockfd_, (struct sockaddr *)&temp_addr, &temp_len) == -1) {
        FATAL("getsockname");
        exit(1);
    }

    if (listen(server_sockfd_, BACKLOG) == -1) {
        FATAL("socket listen");
        exit(1);
    }

    INFO("Server is listening on port %d\n", port_);

    LoopAccepting(server_sockfd_);
}

int HttpServer::Receive(HttpRequest& request, int client_sockfd) {

    size_t num_parsed = 0;
    char buf[HTTP_MESSAGE_MAX_LEN];
    ssize_t bytes_received = 0;

    if ((bytes_received = recv(client_sockfd, buf, HTTP_MESSAGE_MAX_LEN, 0)) < 0) {
        ERROR("No byte to receive\n", bytes_received);
        return -1;
    }
    DEBUG("Received %d bytes\n%s\n", bytes_received, buf);

    http_parser* parser = (http_parser*) malloc(sizeof(http_parser));
    http_parser_init(parser, HTTP_REQUEST);


    http_parser_settings setting;
    num_parsed = http_parser_execute(parser, &setting, buf, bytes_received);
    DEBUG("Parser raw %s\n", http_method_str((enum http_method)parser->method));

    if (num_parsed != bytes_received) {
        ERROR("Parse http request error.\n");
        return -1;
    }

    return num_parsed;
}

int HttpServer::Answer(HttpResponse response, int client_sockfd) {

    const char* buf = response.ToString().c_str();
    ssize_t bytes_sent = 0;
    size_t response_len = response.ToString().length();

    if ((bytes_sent = send(client_sockfd, buf, response_len, 0)) < 0) {
        ERROR("No data to send.\n");
        return -1;
    }
    DEBUG("Answered %d bytes\n%s\n", bytes_sent, buf);

    return 0;

}

void HttpServer::LoopAccepting(int server_sockfd) {

    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_len;

    for (;;) {
        pthread_t pt;
        client_len = sizeof(struct sockaddr);
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr*) &client_addr, &client_len)) == -1) {
            if (errno == EINTR) {
                ERROR("accept");
                continue;
            } else {
                FATAL("accept");
                exit(0);
            }
        }
        current_client_sockfd_ = client_sockfd;

        if (pthread_create(&pt, NULL, client_thread_func, this) != 0) {
            ERROR("pthread_create");
            continue;
        }
    }
}
