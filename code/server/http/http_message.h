/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include "HttpEnums.h"
#include <map.h>

using namespace std;

class HttpMessage {

    public:

        void set_headers(map<string, string> headers) { headers_ = headers; }
        map<string, string> headers() { return headers_; }

        void set_body(byte* body) { body_ = body; }
        byte* body() { return body_; }

        void AddHeaderItem(string name, string value) { headers_[name] = value; }

    private:

        map<string, string> headers_;
        byte* body_;
        
}

class HttpRequest: HttpMessage {

    public:
        void set_method(HttpMethod method) { method_ = method; }
        HttpMethod method() { return method_; }

        void set_path(string path) { path_ = path; }
        string path() { return path_; }

        void set_version(string version) { version_ = version; }
        string version() { return version_; }

        void set_keep_alive(bool keep_alive) { keep_alive_ = keep_alive; }
        bool keep_alive() { return keep_alive_; }

    private:
        HttpMethod method_;
        string path_;
        string version_;
        bool keep_alive_;
}

class HttpResponse: HttpMessage {

    public:
        void set_status(HttpStatus status) { status_ = status; }
        HttpStatus status() { return status_; }

    private:
        HttpStatus status_;
}

#endif
