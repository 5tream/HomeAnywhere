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
* @file rest_server.h
* @brief A rest_server implemented with http_server
* @author Rye Yao
* @version 0.1
* @date 2013-06-18
*/

#ifndef REST_SERVER_H
#define REST_SERVER_H

#include "resource.h"
#include "http_method.h"

class RESTServer {
    public:

        RESTServer(int port) {
            port_ = port;
        }

        void AddResource(Resource* resource) {
            switch (resource->http_method()) {
                case GET:
                    get_resources_.AddResource(resource);
                case PUT:
                    put_resources_.AddResource(resource);
                case POST:
                    post_resources_.AddResource(resource);
                case DELETE:
                    delete_resources_.AddResource(resource);
            }
        }

        void Start();
        
    private:
        Resources get_resources_;
        Resources put_resources_;
        Resources post_resources_;
        Resources delete_resources_;
        int port_;
};

#endif
