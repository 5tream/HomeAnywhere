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
*/
/**
* @file http_client.h
* @brief A simple http client to perform http request and hold response
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include "http_request.h"
#include "http_response.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#define MY_AGENT "Rye's SimpleHttpClient"

class HttpClient {
    public:
        HttpClient(string ip, int port) {
            ip_ = ip;
            port_ = port;
            sockfd_ = -1;
            keep_alive_ = true;
            bzero(&servaddr, sizeof(servaddr));
            servaddr.sin_family = AF_INET;
            servaddr.sin_port = htons(port);
            inet_pton(AF_INET, ip.c_str(), &servaddr.sin_addr);
            // Get host
            char host_name[128];
            struct hostent *host_ent;
            gethostname(host_name, sizeof(host_name));
            host_ent = gethostbyname(host_name);

            //host_ = string(inet_ntoa(*(struct in_addr*)(host_ent->h_addr_list[0])));
            host_ = ip;
        }

        ~HttpClient() {
            if(sockfd_ <= 0) {
                close(sockfd_);
            }
        }
        HttpResponse Get(const string& path);
        HttpResponse Post(string path, string content_type, string data);
        HttpResponse Put(string path, string content_type, string data);
        HttpResponse Delete(string path, string content_type, string data);
        void set_keep_alive(bool keep_alive) {
            keep_alive_ = keep_alive;
        }

    private:
        HttpResponse Send(HttpRequest request);
        int Connect();

    private:
        string host_;
        struct sockaddr_in servaddr;
        string ip_;
        int port_;
        int sockfd_;
        bool keep_alive_;
};

#endif
