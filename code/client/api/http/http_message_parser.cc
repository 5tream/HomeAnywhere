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
* @file http_message_parser.cc
* @brief Parse Http message (request/response)
* @author Rye Yao
* @version 0.1
* @date 2013-06-08
*/

#include "http_message_parser.h"
#include "http_message.h"
#include "http_request.h"
#include "http_response.h"
#include "utils_log.h"

#include <stdlib.h>

int on_url_cb(http_parser* parser, const char* at, size_t len) {
    
    HttpMessageParser* this_ptr = (HttpMessageParser*)parser->data;
    this_ptr->temp_url_seg_ += string(at, len);
    return 0;
}

int on_header_field_cb(http_parser* parser, const char* at, size_t len) {
    HttpMessageParser* this_ptr = (HttpMessageParser*)parser->data;
    this_ptr->temp_hfield_ = string(at, len);
    return 0;
}

int on_header_value_cb(http_parser* parser, const char* at, size_t len) {
    HttpMessageParser* this_ptr = (HttpMessageParser*)parser->data;
    HttpMessage* http_msg = this_ptr->message_;
    http_msg->AddHeaderItem(this_ptr->temp_hfield_, string(at, len));
    return 0;
}

int on_body_cb(http_parser* parser, const char* at, size_t len) {

    HttpMessageParser* this_ptr = (HttpMessageParser*)parser->data;
    if (!this_ptr->body_base_) {
        this_ptr->body_base_ = at;
    }
    this_ptr->body_len_ += len;
    return 0;
}

int on_message_begin_cb(http_parser* parser) {
    return 0;
}

int on_status_complete_cb(http_parser* parser) {
    HttpResponse* http_resp = (HttpResponse*)((HttpMessageParser*)parser->data)->message_;
    http_resp->set_status((HttpStatus)parser->status_code);
    return 0;
}

int on_headers_complete_cb(http_parser* parser) {
    return 0;
}

int on_message_complete_cb(http_parser* parser) {

    HttpMessageParser* this_ptr = (HttpMessageParser*)parser->data;
    HttpMessage* http_msg = this_ptr->message_;
    http_msg->set_body(string(this_ptr->body_base_, this_ptr->body_len_));

    return 0;
}

HttpMessageParser::HttpMessageParser(HttpMessage* message, bool is_request) {
    parser_ = (http_parser*) malloc(sizeof(http_parser));
    message_ = message;
    is_request_ = is_request;
    temp_url_seg_ = "";
    body_base_ = NULL;
    body_len_ = 0;
    parser_->data = this;

    settings_.on_message_begin = on_message_begin_cb;
    settings_.on_url = on_url_cb;
    settings_.on_status_complete = on_status_complete_cb;
    settings_.on_header_field = on_header_field_cb;
    settings_.on_header_value = on_header_value_cb;
    settings_.on_headers_complete = on_headers_complete_cb;
    settings_.on_body = on_body_cb;
    settings_.on_message_complete = on_message_complete_cb;
}

HttpMessageParser::~HttpMessageParser() {
    free(parser_);
}

int HttpMessageParser::Parse(char* buf, size_t len) {
    if (is_request_) {
        http_parser_init(parser_, HTTP_REQUEST);
    } else {
        http_parser_init(parser_, HTTP_RESPONSE);
    }
    int num_parsed = http_parser_execute(parser_, &settings_, buf, len);

    if (num_parsed != len) {
        ERROR("Parse HttpMessage error!\n");
        return -1;
    }

    if (is_request_) {
        HttpMethod method = GetMethodFromString(string(http_method_str((enum http_method)parser_->method)));
        HttpRequest* request = (HttpRequest*)message_;
        request->set_method(method);
        request->set_path(temp_url_seg_);
        request->set_version(HH_HTTP_1_1);
    } else {
        HttpResponse* response = (HttpResponse*)message_;
        response->set_version(HH_HTTP_1_1);
    }

    if (http_should_keep_alive(parser_)) {
        message_->set_keep_alive(true);
    } else {
        message_->set_keep_alive(false);
    }

    return 0;
}
