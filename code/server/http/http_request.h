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
 * @file http_request.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "http_message.h"
#include "http_method.h"
#include "http_header_items.h"

#include <string.h>

class HttpRequest: public HttpMessage {

    public:
        void set_method(HttpMethod method) { method_ = method; }
        HttpMethod method() { return method_; }

        void set_path(string path) { path_ = path; }
        string path() { return path_; }

        void set_keep_alive(bool keep_alive) { keep_alive_ = keep_alive; }
        bool keep_alive() { return keep_alive_; }

        string ToString() {
            string res_str, ver_str;
            ver_str = version();
            res_str += GetStringFromMethod(method_) + string(" ") + path_ + string(" ") + ver_str + string("\r\n");
            map<string, string> h = headers();
            for (map<string, string>::iterator it = headers().begin(); it != h.end(); it++) {
                res_str += it->first + string(": ") + it->second + string("\r\n");
            }

            if (keep_alive_) {
                res_str += string(HH_KEEP_ALIVE) + string(": ") + string("true") + string("\r\n");
            }
            res_str += string("\r\n");
            string body(this->body());
            res_str += body;
        }

    private:
        HttpMethod method_;
        string path_;
        string version_;
        bool keep_alive_;
};

#endif
