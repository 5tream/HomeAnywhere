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
* @file post_device.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#include "post_data.h"
#include <ctime>
using namespace std;

Result PostData::Handle(Params* args, string body) {
    Result result;
    string res = "";
    
    string did = args->Get(1);
    string dsid = args->Get(2);
    time_t t = time(NULL);
    string timestamp = asctime(localtime(&t));

    // Get device from queue
    Devices all_devs;
    // Get device queue
    device_queue_->pop(all_devs);
    // Retrive device
    Device* device = all_devs[did];
    if (device == NULL) {
        result.set_result("Device Not found");
        return result;
    }

    device = all_devs[did];

    // Retrive datastream of this device
    DataStream* data_stream = device->data_streams[dsid];
    if (data_stream == NULL) {
        result.set_result("Device does not contains this datastream");
        return result;
    }
    // TODO Push data for different type

    //device->data_streams[data_stream->id] = data_stream;
    // Put it into queue
    device_queue_->push(all_devs);

    result.set_result("Data Posted.");
    return result;
}
