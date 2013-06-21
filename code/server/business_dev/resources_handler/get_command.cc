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
    // Retrive and Pop command
    DEBUG("Retriving command\n");
    if (all_devs[curr_did]->command_queue.empty()) {

        result.set_result("No command retrived");
        device_queue_->push(all_devs);
        return result;
    }
    comm = all_devs[curr_did]->command_queue.front();
    if (comm == NULL) {
        result.set_result("No command retrived");
        device_queue_->push(all_devs);
        return result;
    }
    all_devs[curr_did]->command_queue.pop();
    DEBUG("Command popped up\n");
    // Save device queue
    device_queue_->push(all_devs);
    DEBUG("Device queue pushed back\n");

    result.set_result(comm->command_str);
    if (comm->command_str != "") {
        DEBUG("Command sent %s\n", comm->command_str.c_str());
    } else {
        DEBUG("Empty command string\n");
        result.set_result("");
    }
    return result;
}
