/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/06/06
 */


#include "http_server.h"

HttpServer::HttpServer()
{
    if ((server_sockfd_ = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        FATAL("server_sockfd");
        exit(0);
    }
}

void HttpServer::Listen(int port)
{
    port_ = port;

    struct sockaddr_in server_addr, temp_addr;
    socklen_t temp_len;

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_);

    if (bind(server_sockfd_, 
             (struct sockaddr *) &server_addr,
             sizeof(server_addr)) == -1) {

        FATAL("bind");
        exit(0);
    }

    temp_len = sizeof(struct sockaddr);
    if (getsockname(server_sockfd_, (struct sockaddr *)&temp_addr, &temp_len) == -1) {
        FATAL("getsockname");
        exit(0);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        FATAL("socket listen");
        exit(0);
    }

    INFO("Server is listening on port %d\n", port_);
}
