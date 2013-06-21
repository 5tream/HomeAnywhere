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
 * @file i_http_request_handler.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef IHTTPREQUESTHANDLER_H
#define IHTTPREQUESTHANDLER_H

#include "http_request.h"
#include "http_response.h"
#include "http_method.h"

class IHttpRequestHandler {
    public:

        IHttpRequestHandler(HttpMethod method) { method_ = method; }
        // request:in
        // response:out
        virtual int Handle(HttpRequest request, HttpResponse& response) {}

        // Getters and Setters
        HttpMethod method() { return method_; }

    private:
        HttpMethod method_;
};

#endif
