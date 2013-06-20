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
* @file put_handler.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#include "i_http_request_handler.h"
#include "i_resource_handler.h"
#include "http_status.h"
#include "put_handler.h"

int PutHandler::Handle(HttpRequest request, HttpResponse& response) {
    string url = request.path();
    Params* params = new Params();

    IResourceHandler* handler;

    if((handler = resources_.Find(url, params)) == NULL) {
        DEBUG("Resource not found\n");
        response.set_status(NOT_FOUND_404);
        return -1;
    }

    Result res = handler->Handle(params);
    response.set_body(res.result());
    response.set_status(OK_200);

    return 0;
}

