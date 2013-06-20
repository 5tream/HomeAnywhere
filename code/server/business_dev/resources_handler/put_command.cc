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
* @file put_command.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#include "put_command.h"

Result PutCommand::Handle(Params* args) {
    Result result;
    string res = "";

    //TODO put command to queue
    // Create an command
    Command* comm = new Command();

    comm->to_did = args->Get(1);
    comm->command_str = args->Get(2);

    Devices all_devs;
    // Get device queue
    device_queue_->pop(all_devs);
    // add command
    all_devs[comm->to_did]->command_queue.push(comm);
    // Save device queue
    device_queue_->push(all_devs);
}
