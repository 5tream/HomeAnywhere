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
* @file resource.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#include "resource.h"
#include "i_resource_handler.h"
#include "utils_log.h"

IResourceHandler* Resources::Find(string url, Params* params) {
    map<UrlTemplate*, Resource*>::iterator it = resources_.begin();
    for(; it != resources_.end(); it++) {
        UrlTemplate* tmp = (*it).first;
        if(tmp->Match(url, params)) {
            return (*it).second->resource_handler();
        }
    }

    return NULL;
}


