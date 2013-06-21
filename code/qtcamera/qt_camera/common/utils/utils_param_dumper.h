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
* @file utils_dump_param_name.h
* @brief used for print the name of a param based on it's type
* @author Rye Yao
* @version 0.1
* @date 2013-06-15
*/

#ifndef UTILS_DUMP_PARAM_NAME_H
#define UTILS_DUMP_PARAM_NAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

static void dumpMem(unsigned char* p, unsigned int s) {
    int i;
    unsigned char c[0x10];

    printf (">>      ");

    for(i = 0; i < 0x10; i++) {
        printf(" +%x", i);
    }
    printf(" +");

    for(i = 0; i < 0x10; i++) {
        printf("%x", i);
    }
    printf("\n");

    for(i = 0; i < ((s + 15) & 0xfff0); i++) {
        if ((i % 0x10) == 0) {
            if (i != 0) {
                printf(" %*.*s\n", 0x10, 0x10, c);
            }
            printf(">> %04x", i);
        }

        if (i < s) {
            printf(" %02x", p[i]);
            c[i & 0xf] = ((p[i] < 0x20) || (p[i] > 0x7e)) ? '.' : p[i];
        } else {
            printf("   ");
            c[i & 0xf] = ' ';
        }
    }
    printf("  %*.*s\n", 0x10, 0x10, c);
}

#define DUMPINT(x) do{printf("%s:%d\n",#x,x);dumpMem((char*)(&x),sizeof(int));}while(0)
#define DUMPSTR(x) do{printf("%s:%s\n",#x,x);dumpMem(x,strlen(x));}while(0)
#define DUMPMEM(x,s) do{printf("%s:\n",#x);dumpMem((char*)(&x),s);}while(0)

#ifdef __cplusplus
}
#endif

#endif
