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
* @file put_handler.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#ifndef PUTHANDLER_H
#define PUTHANDLER_H
#include "resource.h"

class PutHandler: public IHttpRequestHandler {

    public:
        PutHandler(Resources resources, HttpMethod method): IHttpRequestHandler(method) {
            resources_ = resources;
        }
        int Handle(HttpRequest request, HttpResponse& response);

    private:
        Resources resources_;
};

#endif
