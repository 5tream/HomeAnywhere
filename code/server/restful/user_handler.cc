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
* @file user_handler.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#include "user_handler.h"
#include <stdio.h>

const char* get_users(string method, PARAMS params) {

    printf("method is %s\n", method.c_str());
    return string("hello").c_str();
}
