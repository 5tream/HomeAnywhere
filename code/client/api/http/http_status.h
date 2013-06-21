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
 * @file http_status.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef HTTPSTATUS_H
#define HTTPSTATUS_H

enum HttpStatus {
   OK_200 = 200,

   FORBIDDEN_403 = 403,
   NOT_FOUND_404 = 404,
   INTERNAL_SERVER_ERROR_500 = 500
   // TODO add the rests
};

static string GetStringFromStatus(HttpStatus status) {
    switch(status) {
        case 200:
            return "OK";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 500:
            return "Internal Server Error";
        default:
            return "OK";
    }
}

#endif
