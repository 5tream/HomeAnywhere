/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPMETHOD_H
#define HTTPMETHOD_H

#include "http_message.h"
#include "i_http_request_handler.h"

class IHttpMethod
{
    public:
        HttpMethod(IHttpRequestHandler handler) { handler_ = handler; }
        
    public:
        IHttpRequestHandler handler_;
}

#endif
