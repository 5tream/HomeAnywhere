/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include <map.h>

using namespace std;

class HttpMessage {

    public:

        void AddHeaderItem(string name, string value) { headers_[name] = value; }
        void GetHeaderItem(string name) { return headers_[name]; }

        // getters and setters
        void set_headers(map<string, string> headers) { headers_ = headers; }
        map<string, string> headers() { return headers_; }

        void set_body(byte* body) { body_ = body; }
        byte* body() { return body_; }


    private:

        map<string, string> headers_;
        byte* body_;
        
}

#endif
