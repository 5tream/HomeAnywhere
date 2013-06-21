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

#include "my_callbackfunc.h"
#include <unistd.h>

void MyCallback::Callback(string command) {

    INFO("Received command : %s\n", command.c_str());
    if (command == "No command retrived") {
        sleep(3);
    }
}
