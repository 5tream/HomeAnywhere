/**
 * Author: Rye Yao
 * E-mail: rye.y.cn@gmail.com
 * Date: 2013/04/08
 */

#ifndef UTILSLOG_H
#define UTILSLOG_H

#include <stdio.h>

#ifdef __DEBUG
#define DEBUG(format,...) printf("\n\033[1;32m["__DATE__"]["__TIME__"][DEBUG ==> File: "__FILE__" Line:%5d] \n"format"\033[0m\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(format)
#endif //__DEBUG

#ifdef __INFO
#define INFO(format,...) printf("\n\033[1;34m["__DATE__"]["__TIME__"][INFO  ==> File: "__FILE__" Line: %5d] \n"format"\033[0m\n", __LINE__, ##__VA_ARGS__)
#else
#define INFO(format)
#endif //__INFO

#ifdef __ERROR
#define ERROR(format,...) printf("\n\033[1;31m["__DATE__"]["__TIME__"][ERROR ==> File: "__FILE__" Line: %5d] \n"format"\033[0m\n", __LINE__, ##__VA_ARGS__)
#else
#define ERROR(format)
#endif //__ERROR

#ifdef __FATAL
#define FATAL(format,...) fprintf(stderr, "\n\033[41;1;32m["__DATE__"]["__TIME__"][FATAL ==> File: "__FILE__" Line: %5d] \n%s\n"format"\033[0m\n", __LINE__, strerror(errno), ##__VA_ARGS__)
#else
#define FATAL(format)
#endif //__FATAL

#endif
