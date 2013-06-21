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
* @file get_users.h
* @brief Get all users
* @author Rye Yao
* @version 0.1
* @date 2013-06-18
*/

#ifndef GET_USERS_H
#define GET_USERS_H

#include "i_resource_handler.h"

class GetUsers: public IResourceHandler {

    public:
        GetUsers(){}
        Result Handle(Params* args);
};

#endif

