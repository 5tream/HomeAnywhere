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
* @file demo_client.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#include "device_api.h"
#include "my_callbackfunc.h"

int main (int argc, char** argv) {
    
    if (argc != 3) {
        INFO("usage: demo_client <ip> <port>\n");
        exit(0);
    }

    string ip = string(argv[1]);
    int port = atoi(argv[2]);
    DeviceAPI dev_api(ip, port);

    Device device;
    device.id = "1";
    device.owner_id = "1";

    dev_api.Init(device);
    MyCallback mycallback;
    dev_api.RegisterCallback(&mycallback);

    // Loop Posting data
    while (true) {
        dev_api.PostData("1", "jpeg", "fdafasdfdsa"); 
    }

}
