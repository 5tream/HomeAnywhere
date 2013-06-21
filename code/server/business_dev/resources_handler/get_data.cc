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
* @file get_data.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-21
*/

#include "get_data.h"
#include "utils_log.h"
#include "http_client.h"
#include <string>

Result GetData::Handle(Params* args, string body) {

    Result result;
    string res = "";
    string streamer_ip = args->Get(2);

    // Get data from queue
    // Prepare an command structure
    Command *comm;

    Devices all_devs;
    // Get device queue
    // Retrive and publish data
    DEBUG("Retriving data\n");
    HttpClient hc(streamer_ip, 8080);
    HttpResponse response = hc.Get("/");

    result.set_result(response.body());
    return result;
}
