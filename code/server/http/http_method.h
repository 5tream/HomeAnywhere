/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/05
 */

#ifndef HTTPMETHOD_H
#define HTTPMETHOD_H

typedef enum HttpMethod
{
    GET,
    PUT,
    POST,
    DELETE
}HttpMethod;

static string GetStringFromMethod(HttpMethod method) {
    switch(method) {
        case GET:
            return "GET";
        case PUT:
            return "PUT";
        case POST:
            return "POST";
        case DELETE:
            return "DELETE";
    }
}

#endif
