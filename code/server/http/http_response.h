/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "http_message.h"
#include "http_status.h"

class HttpResponse: public HttpMessage {

    public:
        void set_status(HttpStatus status) { status_ = status; }
        HttpStatus status() { return status_; }

    private:
        HttpStatus status_;
}

#endif
