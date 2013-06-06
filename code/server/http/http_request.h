/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
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
