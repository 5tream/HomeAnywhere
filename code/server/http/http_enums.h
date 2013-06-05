/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPENUMS_H
#define HTTPENUMS_H

enum HttpMethod {
    GET,
    PUT,
    POST,
    DELETE
}

enum HttpStatus {
   OK_200 = 200,

   FORBIDDEN_403 = 403
   NOT_FOUND_404 = 404,
   INTERNAL_SERVER_ERROR_500 = 500,
   // TODO add the rests
}

#endif
