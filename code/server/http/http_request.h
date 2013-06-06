/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "http_message.h"
#include "i_http_method.h"

#include <string.h>

class HttpRequest: public HttpMessage {

    public:
        void set_method(IHttpMethod method) { method_ = method; }
        IHttpMethod method() { return method_; }

        void set_path(string path) { path_ = path; }
        string path() { return path_; }

        void set_version(string version) { version_ = version; }
        string version() { return version_; }

        void set_keep_alive(bool keep_alive) { keep_alive_ = keep_alive; }
        bool keep_alive() { return keep_alive_; }

    private:
        IHttpMethod method_;
        string path_;
        string version_;
        bool keep_alive_;
}

#endif
