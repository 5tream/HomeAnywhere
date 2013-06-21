/* Copyright (C) 
 * 2013 - Rye Yao
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */
/**
 * @file main.cc
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
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
