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
 * @file http_method.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef HTTPMETHOD_H
#define HTTPMETHOD_H

typedef enum HttpMethod
{
    GET,
    PUT,
    POST,
    DELETE
}HttpMethod;

static string GetStringFromMethod(HttpMethod method) {
    switch(method) {
        case GET:
            return "GET";
        case PUT:
            return "PUT";
        case POST:
            return "POST";
        case DELETE:
            return "DELETE";
    }
}

static HttpMethod GetMethodFromString(string method) {
    if (method == "GET") {
        return GET;
    } else if (method == "PUT") {
        return PUT;
    } else if (method == "POST") {
        return POST;
    } else if (method == "DELETE") {
        return DELETE;
    }
}
#endif
