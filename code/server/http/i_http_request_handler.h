/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/04/12
 */

#ifndef IHTTPREQUESTHANDLER_H
#define IHTTPREQUESTHANDLER_H

#include "http_request.h"
#include "http_response.h"
#include "i_http_method.h"

class IHttpRequestHandler {
    public:
        IHttpRequestHandler(IHttpMethod method) { method_ = method; }
        virtual ~IHttpRequestHandler() = 0;
        virtual HttpResponse handle(HttpRequest request) = 0;

        // Getters and Setters
        IHttpMethod method() { return method_; }

    private:
        IHttpMethod method_;
}

#endif
