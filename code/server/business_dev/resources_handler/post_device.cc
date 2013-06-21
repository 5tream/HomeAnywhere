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

#include "post_device.h"
#include <ctime>
using namespace std;

Result PostDevice::Handle(Params* args, string data) {
    Result result;
    string res = "";
    
    time_t t = time(NULL);
    string timestamp = asctime(localtime(&t));

    //TODO put device to queue
    // Create an device
    Device* device = new Device();
    device->owner_id = args->Get(0);
    device->id = args->Get(1);
    device->name = "default";
    device->description = "default";

    DataStream* data_stream = new DataStream();
    data_stream->id = "1";
    data_stream->name = "default";
    data_stream->data_type = "default";
    data_stream->timestamp = timestamp;

    device->data_streams[data_stream->id] = data_stream;

    Control* control = new Control();
    control->id = "1";
    control->name = "move_forword";
    control->command_str = "mf";
    control->description = "default";

    device->controls[control->id] = control;
    // Put it into queue

    Devices all_devs;
    // Get device queue
    DEBUG("Retriving device queue...\n");
    device_queue_->pop(all_devs);
    DEBUG("device queue got\n");
    // add device
    all_devs[device->id] = device;
    device_queue_->push(all_devs);
    DEBUG("Device queue pushed back\n");

    result.set_result("Device Posted.");
    return result;
}
