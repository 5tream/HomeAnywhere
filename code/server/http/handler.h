/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/04/12
 */

#ifndef HTTPHANDLER_H
#define HTTPHANDLER_H

#define SOCKETIO_BUFFER_SIZE 512

virtual class HttpHandler {
    virtual HttpHandler();
    virtual ~HttpHandler();

    virtual HttpResponse handle(HttpRequest request);
}

#endif
