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
* @file get_handler.h
* @brief Implement IHttpRequestHandler to handle GET request
* @author Rye Yao
* @version 0.1
* @date 2013-06-18
*/

#ifndef GETHANDLER_H
#define GETHANDLER_H
#include "resource.h"

class GetHandler: public IHttpRequestHandler {

    public:
        GetHandler(Resources resources, HttpMethod method):IHttpRequestHandler(method) {
            resources_ = resources;
        }
        int Handle(HttpRequest request, HttpResponse& response);

    private:
        Resources resources_;

};

#endif
