/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/06
 */

#ifndef HANDLERGET_H
#define HANDLERGET_H

#include "i_http_request_handler.h"

class GetHandler: public IHttpRequestHandler {
    public:
        GetHandler(HttpMethod method): IHttpRequestHandler(method) {}
        int Handle(HttpRequest request, HttpResponse& response);
};

#endif
