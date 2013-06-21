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
* @file rest_server.cc
* @brief A rest_server implemented with http_server
* @author Rye Yao
* @version 0.1
* @date 2013-06-18
*/

#include "rest_server.h"
#include "http_server.h"
#include "get_handler.h"
#include "put_handler.h"
#include "post_handler.h"

void RESTServer::Start() {
   HttpServer http_server;

   GetHandler get_handler(get_resources_, GET);
   PutHandler put_handler(put_resources_, PUT);
   PostHandler post_handler(post_resources_, POST);

   http_server.AddHandler(&get_handler);
   http_server.AddHandler(&put_handler);
   http_server.AddHandler(&post_handler);

   http_server.Listen(port_);
}
