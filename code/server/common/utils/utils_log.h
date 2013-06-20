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
 * @file utils_log.h
 * @brief 
 * @author Rye Yao
 * @version 0.1
 * @date 2013-06-07
 */

#ifndef UTILSLOG_H
#define UTILSLOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#ifdef __DEBUG
#define DEBUG(format,...) printf("\n\033[1;32m["__DATE__"]["__TIME__"][DEBUG ==> "__FILE__":%d | ", __LINE__); \
    printf("%s]\n", __PRETTY_FUNCTION__); \
    printf(format"\033[0m\n", ##__VA_ARGS__)
#else
#define DEBUG(format)
#endif //__DEBUG

#ifdef __INFO
#define INFO(format,...) printf("\n\033[1;34m["__DATE__"]["__TIME__"][INFO  ==> "__FILE__":%d | ", __LINE__); \
    printf("%s]\n", __PRETTY_FUNCTION__); \
    printf(format"\033[0m\n", ##__VA_ARGS__)
#else
#define INFO(format)
#endif //__INFO

#ifdef __ERROR
#define ERROR(format,...) printf("\n\033[1;31m["__DATE__"]["__TIME__"][ERROR ==> "__FILE__":%d | ", __LINE__); \
    printf("%s]\n", __PRETTY_FUNCTION__); \
    printf(format"\033[0m\n", ##__VA_ARGS__)
#else
#define ERROR(format)
#endif //__ERROR

#ifdef __FATAL
#define FATAL(format,...) fprintf(stderr, "\n\033[41;1;32m["__DATE__"]["__TIME__"][FATAL ==> "__FILE__":%d | ", __LINE__); \
    printf("%s]\n", __PRETTY_FUNCTION__); \
    printf("%s\n", strerror(errno)); \
    printf(format"\033[0m\n", ##__VA_ARGS__)
#else
#define FATAL(format)
#endif //__FATAL

#ifdef __cplusplus
}
#endif

#endif
