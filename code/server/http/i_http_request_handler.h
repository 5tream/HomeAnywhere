/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/06
 */

#ifndef IHTTPREQUESTHANDLER_H
#define IHTTPREQUESTHANDLER_H

#include "http_request.h"
#include "http_response.h"
#include "http_method.h"

class IHttpRequestHandler {
    public:

        IHttpRequestHandler(HttpMethod method) { method_ = method; }
        // request:in
        // response:out
        virtual int Handle(HttpRequest request, HttpResponse& response) {}

        // Getters and Setters
        HttpMethod method() { return method_; }

    private:
        HttpMethod method_;
};

#endif
