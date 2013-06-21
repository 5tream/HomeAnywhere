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
*/
/**
* @file my_callbackfunc.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#include <unistd.h>
#include <string.h>

#include "my_callbackfunc.h"
#include "command.h"

static void command_callback(int status, void *command, void *ctx)
{
    int serial_fd = (int)ctx;

    if (status == COMMAND_PASS)
    {
        printf("pass command: %s\n", (char *)command);
        write(serial_fd, command, strlen((char *)command));
    }
}

void MyCallback::Callback(string command)
{
    INFO("Received command : %s\n", command.c_str());
    extract_command(command.c_str(), command_callback, (void *)fd_); 
}
