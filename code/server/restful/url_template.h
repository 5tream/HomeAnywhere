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
* @file url_template.h
* @brief 
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#ifndef URL_TEMPLATE_H
#define URL_TEMPLAGE_H

class UrlTemplate {
    public:
        // e.g. /users/{id}/{name} is for applying the 4 http methods(get put post delete) to resource user with id {id} to operate its {name} attribute
        UrlTemplate(string url_str);
        ~UrlTemplate();
}


#endif
