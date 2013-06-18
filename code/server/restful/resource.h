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
#include "i_resource_handler.h"
#include "http_method.h"
using namespace std;


class Resource {
    public:
        Resource(HttpMethod method, string url) {
            http_method_ = method;
            UrlTemplate ut(url);
            url_template_ = &ut;
        }

        ~Resource() {}

        void set_url_template(UrlTemplate* url_template) { url_template_ = url_template; }
        UrlTemplate* url_template() { return url_template_; }
        
        void set_http_method(HttpMethod http_method) { http_method_ = http_method; }
        HttpMethod http_method() { return http_method_; }

        void set_resource_handler(IResourceHandler* resource_handler) { resource_handler_ = resource_handler; }
        IResourceHandler* resource_handler() { return resource_handler_; }

    private:
        UrlTemplate* url_template_;
        HttpMethod http_method_;
        IResourceHandler* resource_handler_;
};

class Resources {
    public:
        Resources(){}
        ~Resources(){}

        void AddResource(Resource* resource) {
            UrlTemplate* ut = resource->url_template();
            resources_[ut] = resource;
        }

        IResourceHandler* Find(string url, Params params);

    private:
        map<UrlTemplate*, Resource*> resources_;
};
#endif

