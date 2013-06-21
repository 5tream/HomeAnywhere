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
* @file get_command.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#include "get_command.h"
#include "utils_log.h"

Result GetCommand::Handle(Params* args, string body) {

    Result result;
    string res = "";
    string curr_uid = args->Get(0);
    string curr_did = args->Get(1);

    // Get command from queue
    // Prepare an command structure
    Command *comm;

    Devices all_devs;
    // Get device queue
    DEBUG("Retriving device queue...\n");
    device_queue_->pop(all_devs);
    DEBUG("device queue got\n");
    if (all_devs[curr_did] == NULL) {
        result.set_result("Device Not Found");
        device_queue_->push(all_devs);
        return result;
    }
    Device* device = all_devs[curr_did];
    // Retrive and Pop command
    DEBUG("Retriving command\n");

    pthread_mutex_lock(&device->qlock);
    device_queue_->push(all_devs);
    while (device->command_queue.empty()) {
        // Put device_queue back so other thread can retrive it
        DEBUG("Device queue pushed back\n");
        pthread_cond_wait(&device->qready, &device->qlock);
    }
    comm = device->command_queue.front();
    device->command_queue.pop();
    pthread_mutex_unlock(&device->qlock);
    
    //if (comm == NULL) {
    //    result.set_result("No command retrived");
    //    device_queue_->push(all_devs);
    //    return result;
    //}

    result.set_result(comm->command_str);
    if (comm->command_str != "") {
        DEBUG("Command sent %s\n", comm->command_str.c_str());
    } else {
        DEBUG("Empty command string\n");
        result.set_result("");
    }
    return result;
}
