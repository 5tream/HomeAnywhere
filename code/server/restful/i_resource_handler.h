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
* @file i_resource_handler.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#ifndef I_RESOURCE_HANDLER_H
#define I_RESOURCE_HANDLER_H

#include <map>
#include <string>
#include "utils_log.h"

using namespace std;

class Params {
    public:
        string Get(int index) {
            return params_[index];
        }

        void Add(int index, string param) {
            params_[index] = param;
        }

        int Size() {
            return params_.size();
        }

    private:
        map<int, string> params_;


};

class Result {
    public:
        void set_result(string result) { result_ = result; }
        string result(){ return result_; }

    private:
        string result_;
};

class IResourceHandler {
    public:
        IResourceHandler(){}
        //virtual ~IResourceHandler();
        virtual Result Handle(Params args){}
};

#endif
