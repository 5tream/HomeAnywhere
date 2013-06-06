/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/06
 */

#include "handler_get.h"
#include "utils_log.h"

int GetHandler::Handle(HttpRequest request, HttpResponse& response) {

    DEBUG("Handle Get request.\n");
    //response.set_version(request.version());
    response.set_version(string("HTTP/1.1"));
    response.set_status(OK_200);
    char* body = "Hello World!";
    DEBUG("Handle Get request2.\n");
    response.set_body(body);

    DEBUG("Handled request %s\n", response.ToString().c_str());

    return 0;
}
