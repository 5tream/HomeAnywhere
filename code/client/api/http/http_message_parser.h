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
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* 
*/
/**
* @file http_message_parser.h
* @brief For parsing http messages (request/response)
* @author Rye Yao
* @version 0.1
* @date 2013-06-08
*/

#ifndef HTTP_MESSAGE_PARSER_H
#define HTTP_MESSAGE_PARSER_H

#include "http_request.h"
#include "http_response.h"
#include "http_parser.h"

class HttpMessageParser {
    
    public:
        HttpMessageParser(HttpMessage* message, bool is_request);
        ~HttpMessageParser();
        int Parse(char* buf, size_t len);

    public:

        http_parser* parser_;
        http_parser_settings settings_;
        HttpMessage* message_;
        bool is_request_;
        string temp_hfield_;
        string temp_url_seg_;
        const char* body_base_;
        size_t body_len_;
};

#endif
