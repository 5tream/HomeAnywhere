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
* @file entities.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-20
*/

#ifndef ENTITIES_H
#define ENTITIES_H

#include <map>
#include <string>
#include <queue>
#include <pthread.h>
using namespace std;

typedef struct DataStream {
    string id;
    string name;
    string data_type;
    string description;
    string timestamp;
}DataStream;

typedef std::map<std::string, DataStream*> DataStreams;

typedef struct Control {
    string id;
    string name;
    string command_str;
    string description;
}Control;

typedef std::map<std::string, Control*> Controls;

typedef struct Command {
    string to_did;
    string command_str;
}Command;

typedef struct Device {
    string id;
    string name;
    string owner_id;
    string description;
    DataStreams data_streams;
    Controls controls;
    queue<Command*> command_queue;
    pthread_cond_t qready;
    pthread_mutex_t qlock;
}Device;

typedef std::map<std::string, Device*> Devices; 


#endif
