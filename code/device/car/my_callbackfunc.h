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
* @file MyCallbackFunc.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#ifndef MYCALLBACKFUNC_H
#define MYCALLBACKFUNC_H

#include "device_api.h"

class MyCallback : public CallbackFunc {

    public:
        MyCallback(int fd)
        {
            fd_ = fd;
        }
        void Callback(string command);
    private:
        int fd_;
};

#endif
