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
 * @file main.cc
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#include "http_client.h"

#include <stdlib.h>
#include <stdio.h>

#include "http_response.h"

int main(int argc, char** argv) {

    int port = 80;
    if (argc == 5) {
        if (strcmp(argv[3], "GET")) {
            INFO("Usage: httpserver <ip> <port> <GET|PUT|DELETE|POST> <path> [data]\n");
            exit(1);
        }
        INFO("FUCK!!!\n");
    } else if (argc != 6) {
        INFO("Usage: httpserver <ip> <port> <GET|PUT|DELETE|POST> <path> [data]\n");
        exit(1);
    }
    DEBUG("00000\n");

    string ip = string(argv[1]);
    DEBUG("12321\n");
    port = atoi(argv[2]);
    DEBUG("121212\n");
    string method = string(argv[3]);
    DEBUG("232323\n");
    string path = string(argv[4]);
    DEBUG("424343\n");
    string data = "";
    if (argc == 6) {
        data = string(argv[5]);
    }
    DEBUG("11111\n");

    HttpClient hc(ip, port);
    HttpResponse response;
    string content_type = "text";
    if (method == "GET") {
        DEBUG("GET\n");
        response = hc.Get(path);
    } else if (method == "PUT") {
        DEBUG("PUT\n");
        response = hc.Put(path, content_type, data);
    } else if (method == "POST") {
        DEBUG("POST\n");
        response = hc.Post(path, content_type, data);
    } else if (method == "DELETE") {
        DEBUG("DELETE\n");
        response = hc.Delete(path, content_type, data);
    }
    DEBUG("2222\n");

    INFO("Response received:\n%s\n", response.ToString().c_str());

    return 0;
}
