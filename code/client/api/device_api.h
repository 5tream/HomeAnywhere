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
* @file device_api.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#ifndef DEVICE_API_H
#define DEVICE_API_H

#include <string>
#include "entities.h"
#include "http_client.h"

class CallbackFunc {
    public:
        virtual void Callback(string command){}
        HttpClient* http_client;
        Device* device;
};

class DeviceAPI {
    public:
        DeviceAPI(string ip, int port) {
            ip_ = ip;
            port_ = port;
        }
        void RegisterCallback(CallbackFunc* callback_func);
        void Init(Device device);
        void PostData(string id, string type, string data);
    private:
        HttpClient* http_client_;
        CallbackFunc* callback_func_;
        Device device_;
        string ip_;
        int port_;
};

#endif
