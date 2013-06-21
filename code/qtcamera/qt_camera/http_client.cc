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
* @file http_client.cc
* @brief A simple http client to perform http request and hold response
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#include "http_client.h"
#include "http_message_parser.h"
#include <stdio.h>
#include "utils_log.h"
#include <QtCore/QVariant>
HttpResponse HttpClient::Send(HttpRequest request) {

    if (sockfd_ < 0) {
        if ((sockfd_ = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            FATAL("socket");
            exit(0);
        }
        int conn_ret = connect(sockfd_, (struct sockaddr*)&servaddr, sizeof(servaddr));
        if (conn_ret == -1) {
            FATAL("connect");
            exit(0);
        }
    }
    if (!keep_alive_) {
        request.AddHeaderItem(HH_CONNECTION, "close");
    }

    // Send
    ssize_t bytes_sent = 0;
    string s = request.ToString();
    size_t request_len = QString::fromStdString(request.ToString()).toLocal8Bit().length();
    char* buf = new char[request_len];
    memcpy(buf, request.ToString().c_str(), request_len);

    if((bytes_sent = send(sockfd_, buf, request_len, 0)) <= 0) {
        if (bytes_sent < 0) {
            FATAL("Send request error.\n");
        } else {
            FATAL("Connection has been forcibly closed by remote client.\n");
        }
        exit(0);
    }

    if (bytes_sent != request_len) {
        FATAL("Send data error.\n");
        exit(0);
    }

    DEBUG("Sent request %d bytes\n%s\n", bytes_sent, buf);
    delete[] buf;

    // Receive
    size_t num_parsed = 0;
    ssize_t bytes_received = 0;
    buf = new char[HTTP_MESSAGE_MAX_LEN];

    if ((bytes_received = recv(sockfd_, buf, HTTP_MESSAGE_MAX_LEN, 0)) <= 0) {
        if (bytes_received < 0) {
            FATAL("No byte to receive\n", bytes_received);
            exit(0);
        } else {
            FATAL("Connection has been forcibly closed by remote client.\n");
            exit(0);
        }
    }

    DEBUG("Received raw data %d bytes\n%s\n", bytes_received, buf);
    HttpResponse response;
    HttpMessageParser parser(&response, false);

    if(parser.Parse(buf, bytes_received) < 0) {
        FATAL("Parse http response error.\n");
        exit(0);
    }

    delete[] buf;
    DEBUG("Response parsed %s\n", response.ToString().c_str());
    if ((request.GetHeaderItem(HH_CONNECTION) == "close") || (response.GetHeaderItem(HH_CONNECTION) == "close")) {
        if (sockfd_ >= 0) {
            close(sockfd_);
        }
    }
    return response;
}

HttpResponse HttpClient::Get(const string& url) {

    HttpRequest request;
    request.set_method(GET);
    request.set_path(url);
    request.AddHeaderItem(HH_CONNECTION, "");
    request.AddHeaderItem(HH_HOST, host_);
    request.AddHeaderItem(HH_USER_AGENT, MY_AGENT);

    return Send(request);
}

HttpResponse HttpClient::Post(string url, string content_type, string data) {

    HttpRequest request;
    request.set_method(POST);
    request.set_path(url);
    request.AddHeaderItem(HH_HOST, host_);
    request.AddHeaderItem(HH_USER_AGENT, MY_AGENT);
    request.AddHeaderItem(HH_CONTENT_TYPE, content_type);
    request.set_body(data);

    return Send(request);
}

HttpResponse HttpClient::Put(string url, string content_type, string data) {

    HttpRequest request;
    request.set_method(PUT);
    request.set_path(url);
    request.AddHeaderItem(HH_HOST, host_);
    request.AddHeaderItem(HH_USER_AGENT, MY_AGENT);
    request.AddHeaderItem(HH_CONTENT_TYPE, content_type);
    request.set_body(data);

    return Send(request);
}

HttpResponse HttpClient::Delete(string url, string content_type, string data) {
    HttpRequest request;
    request.set_method(DELETE);
    request.set_path(url);
    request.AddHeaderItem(HH_HOST, host_);
    request.AddHeaderItem(HH_USER_AGENT, MY_AGENT);
    request.AddHeaderItem(HH_CONTENT_TYPE, content_type);
    request.set_body(data);

    return Send(request);

}
