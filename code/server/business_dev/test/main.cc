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
* @file main.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#include "entities.h"
#include "utils_log.h"
#include "http_server.h"
#include "handler_get.h"
#include "http_get_command.h"

int main(int argc, char** argv) {
    
    int port = 80;

    if (argc == 2) {
        port = atoi(argv[1]);
    } else if (argc > 2) {
        ERROR("usage: business [port]\n\t port: 80 by default.");
        exit(0);
    }

    HttpServer hs;
    HttpGetCommand get_command(GET);
    hs.AddHandler(&get_command);
    hs.Listen(port);

}
