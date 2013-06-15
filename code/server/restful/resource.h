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
* @file resource.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#ifndef RESOURCE_H
#define RESOURCE_H

#include "url_template.h"

class Resource {
    public:
        //Resource();
        //~Resource();
        void set_url_template(UrlTemplate url_template) { url_template_ = url_template; }
        UrlTemplate url_template() { return url_template_; }
        
        void set_http_method(HttpMethod http_method) { http_method_ = http_method; }

        void set_resource_handler(IResourceHandler resource_handler) { resource_handler_ = resource_handler; }
        void* resource_handler() { return resource_handler_; }

    private:
        UrlTemplate url_template_;
        HttpMethod http_method_;
        IResourceHandler resource_handler_;
}

#endif

