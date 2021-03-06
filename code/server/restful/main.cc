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
* @brief A demo to set up a rest server
* @author Rye Yao
* @version 0.1
* @date 2013-06-18
*/

#include <stdlib.h>
#include <stdio.h>
#include "i_resource_handler.h"
#include "resource.h"
#include "utils_log.h"
#include "http_server.h"
#include "http_method.h"
#include "get_users.h"
#include "rest_server.h"

int main(int argc, char** argv) {

    int port = 80;

    if (argc == 2) {
        port = atoi(argv[1]);
    } else if (argc > 2) {
        ERROR("usage: restserver [port]\n\t port: 80 by default.");
        exit(0);
    }

    // Create resources
    Resource *devices_resource = new Resource(GET, "/users/{0}/devices/{1}");
    Resource *users_resource = new Resource(GET, "/users/{0}");
    
    // Set resource handler
    GetUsers *gu = new GetUsers();
    users_resource->set_resource_handler(gu);

    // Add resource to REST server
    RESTServer rest_server(port);
    rest_server.AddResource(users_resource);

    // Start REST server
    rest_server.Start();

}
