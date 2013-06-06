/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPSTATUS_H
#define HTTPSTATUS_H

enum HttpStatus {
   OK_200 = 200,

   FORBIDDEN_403 = 403,
   NOT_FOUND_404 = 404,
   INTERNAL_SERVER_ERROR_500 = 500
   // TODO add the rests
};

static string GetStringFromStatus(HttpStatus status) {
    switch(status) {
        case 200:
            return "OK";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 500:
            return "Internal Server Error";
        default:
            return "OK";
    }
}

#endif
