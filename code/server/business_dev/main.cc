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
#include "put_command.h"
#include "get_command.h"
#include "post_device.h"
#include "post_data.h"
#include "get_data.h"
#include "rest_server.h"

int main(int argc, char** argv) {

    int port = 80;

    if (argc == 2) {
        port = atoi(argv[1]);
    } else if (argc > 2) {
        ERROR("usage: restserver [port]\n\t port: 80 by default.");
        exit(0);
    }

    Queue<Devices> device_queue;
    Devices devices;
    device_queue.push(devices);

    // Create resources
    Resource *put_command_res = new Resource(PUT, "/users/{0}/devices/{1}/command/{2}");
    Resource *get_command_res = new Resource(GET, "/users/{0}/devices/{1}/command");
    Resource *post_device_res = new Resource(POST, "/users/{0}/devices/{1}");
    Resource *post_data_res = new Resource(POST, "/users/{0}/devices/{1}/datastream/{2}");
    Resource *get_data_res = new Resource(GET, "/users/{0}/devices/{1}/datastream/{2}");

    
    // Set resource handler
    PutCommand *pc = new PutCommand(&device_queue);
    put_command_res->set_resource_handler(pc);

    GetCommand *gc = new GetCommand(&device_queue);
    get_command_res->set_resource_handler(gc);

    PostDevice *pd = new PostDevice(&device_queue);
    post_device_res->set_resource_handler(pd);

    PostData *pda = new PostData(&device_queue);
    post_data_res->set_resource_handler(pda);

    GetData *gda = new GetData(&device_queue);
    get_data_res->set_resource_handler(gda);
    // Add resource to REST server
    RESTServer rest_server(port);
    rest_server.AddResource(put_command_res);
    rest_server.AddResource(get_command_res);
    rest_server.AddResource(post_device_res);
    rest_server.AddResource(post_data_res);
    rest_server.AddResource(get_data_res);

    // Start REST server
    rest_server.Start();

}
