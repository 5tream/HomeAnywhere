/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/06
 */
#include "http_server.h"
#include "handler_get.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int port = 80;
    if (argc > 2) {
        INFO("Usage: httpserver <port>\n");
        exit(1);
    } else if (argc == 2) {
        port = atoi(argv[1]);
    }

    HttpServer hs;
    GetHandler get_handler(GET);
    hs.AddHandler(&get_handler);
    hs.Listen(port);

    return 0;
}
