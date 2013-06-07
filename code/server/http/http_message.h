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

#include <map>
#include <string>

using namespace std;

class HttpMessage {

    public:

        void AddHeaderItem(string name, string value) { headers_[name] = value; }
        string GetHeaderItem(string name) { return headers_[name]; }

        // getters and setters
        void set_headers(map<string, string> headers) { headers_ = headers; }
        map<string, string> headers() { return headers_; }

        void set_body(char* body) { body_ = body; }
        char* body() { return body_; }

        void set_version(string version) { version_ = version; }
        string version() { return version_; }

        string ToString();

    private:

        map<string, string> headers_;
        string version_;
        char* body_;
        
};

#endif
