/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
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
