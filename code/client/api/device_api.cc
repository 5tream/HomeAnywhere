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
* @file device_api.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#include "device_api.h"
#include <pthread.h>

void* callback(void * arg) {

    CallbackFunc* cb = (CallbackFunc*)arg;

    //TODO loop GETting command from server
    while(true) {
        HttpResponse resp;
        resp = cb->http_client->Get("/users/"+cb->device->owner_id+"/devices/"+cb->device->id+"/command");
        if(resp.content_length() > 0) {
            cb->Callback(resp.body());
        }
    }

}
void DeviceAPI::RegisterCallback(CallbackFunc* callback_func) {

    callback_func_ = callback_func;
    callback_func_->http_client = http_client_;
    callback_func_->device = &device_;

    pthread_t pt;
    if (pthread_create(&pt, NULL, callback, callback_func_) != 0) {
        ERROR("pthread_create");
        exit(0);
    }
}

void DeviceAPI::Init(Device device) {
    device_ = device;
    http_client_ = new HttpClient(ip_, port_);

}

void DeviceAPI::PostData(string id, string type, string data) {
    HttpResponse response;
    // TODO add data resource
    string path = "/users/" + device_.owner_id + "/devices/" + device_.id + "/datastream/" + id;

    response = http_client_->Post(path, type, data);
    INFO("Response received:\n%s\n", response.ToString().c_str());
}
