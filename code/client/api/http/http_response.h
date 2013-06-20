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
 * @file http_response.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "http_message.h"
#include "http_status.h"
#include <sstream>
#include <string>
#include "utils_log.h"

using namespace std;

class HttpResponse: public HttpMessage {

    public:
        void set_status(HttpStatus status) { status_ = status; }
        HttpStatus status() { return status_; }

        string ToString() {
            string res_str, ver_str;
            ver_str = version();

            stringstream ss;
            ss << status_;

            res_str += ver_str + string(" ") + string(ss.str()) + string(" ") + GetStringFromStatus(status_) + string("\r\n");

            map<string, string> h = headers();
            for (map<string, string>::iterator it = h.begin(); it != h.end(); it++) {
                res_str += it->first + string(": ") + it->second + string("\r\n");
            }
            if (this->keep_alive()) {
                //res_str += string(HH_CONNECTION) + string(": ") + string("keep-alive") + string("\r\n");
            } else {
                res_str += string(HH_CONNECTION) + string(": ") + string("close") + string("\r\n");
            }

            res_str += string("\r\n");
            if (this->content_length() == 0) {
                return res_str;
            }
            res_str += string(this->body());
            return res_str;
        }

    private:
        HttpStatus status_;
};

#endif
