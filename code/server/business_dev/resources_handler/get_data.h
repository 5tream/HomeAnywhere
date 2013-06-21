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
* @file get_data.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#ifndef GET_DATA_H
#define GET_DATA_H

#include "i_resource_handler.h"
#include "Queue.h"
#include "entities.h"

class GetData: public IResourceHandler {

    public:
        GetData(Queue<Devices>* device_queue) {
            device_queue_ = device_queue;
        }
        Result Handle(Params* args, string body);
    private:
        Queue<Devices>* device_queue_;
};

#endif
