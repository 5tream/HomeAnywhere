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
* @file url_template.cc
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#include "url_template.h"
#include "utils_log.h"

#include <stdlib.h>
#include <string>
#include <map>
#include <sstream>

using namespace std;

UrlTemplate::UrlTemplate(string url_str) {

    url_str_ = url_str;
    url_list_ = Split(url_str_, '/');
    
}

bool UrlTemplate::Match(string url_to_match, Params params) {

    DEBUG("Begin to match\n");
    vector<string> to_match_list = Split(url_to_match, '/');
    return Match(to_match_list, params);
}

bool UrlTemplate::Match(vector<string> to_match_list, Params params) {

    DEBUG("Begin to match 2\n");
    vector<string>::iterator it_m = url_list_.begin();
    vector<string>::iterator it_s = to_match_list.begin();

    map<int, string> pars;

    for (;
            it_m != url_list_.end()
            && it_s != to_match_list.end();
            it_m++, it_s++) {
        DEBUG("matching...\n");
        string tmp_m = *it_m;
        string tmp_s = *it_s;
        if ((tmp_m.at(0) == '{') && (tmp_m.at(tmp_m.length() - 1) == '}')) {
            int index = atoi(tmp_m.substr(0, tmp_m.length() - 1).c_str());
            pars[index] = tmp_s;
            continue;

        } else if (tmp_m != tmp_s) {
            return false;
        }
    }

    // Mathces
    DEBUG("Matches\n");
    for (int i = 0; i < pars.size(); i++) {
        params.Add(i, pars[i]);
    }
    DEBUG("Matches and added\n");
    return true;
}

std::vector<std::string> &UrlTemplate::Split(const std::string &s, char delim, std::vector<std::string> &elems) {
    DEBUG("Split 2\n");
        std::stringstream ss(s);
            std::string item;
                while (std::getline(ss, item, delim)) {
                    DEBUG("Spliting...\n");
                            elems.push_back(item);
                                }
                    DEBUG("Split done!\n");
                    return elems;
}


std::vector<std::string> UrlTemplate::Split(const std::string &s, char delim) {
    DEBUG("Split 1\n");
        std::vector<std::string> elems;
            Split(s, delim, elems);
                return elems;
}
