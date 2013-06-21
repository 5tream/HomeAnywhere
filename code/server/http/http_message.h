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
 * @file http_message.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include "http_header_items.h"

#include <map>
#include <string>
#include <iostream>
#include <sstream>

#define HTTP_MESSAGE_MAX_LEN 80*1024
using namespace std;

class HttpMessage {

    public:

        void AddHeaderItem(string name, string value) { headers_[name] = value; }
        string GetHeaderItem(string name) { return headers_[name]; }

        // getters and setters
        void set_headers(map<string, string> headers) { headers_ = headers; }
        map<string, string> headers() { return headers_; }

        void set_body(string body) { 

            if (body == "" || body.length() == 0) {
                body_ = "";
            } else {
                body_ = body; 
                stringstream ss;
                ss<< body_.length();
                headers_[HH_CONTENT_LENGTH] = ss.str(); 
            }
        }
        string body() { return body_; }

        int content_length() { return body_.length(); }

        void set_version(string version) { version_ = version; }
        string version() {

            if (version_ != "") {
                return version_;
            } else {
                return HH_HTTP_1_1;
            }
        }

        void set_keep_alive(bool keep_alive) { keep_alive_ = keep_alive; }
        bool keep_alive() { return keep_alive_; }

        string ToString();

    private:

        map<string, string> headers_;
        string version_;
        string body_;
        bool keep_alive_ = true;
        
};

#endif
