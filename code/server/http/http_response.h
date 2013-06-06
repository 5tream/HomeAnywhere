/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "http_message.h"
#include "http_status.h"
#include <sstream>
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

            res_str += string("\r\n");
            res_str += string(this->body());
            return res_str;
        }

    private:
        HttpStatus status_;
};

#endif
