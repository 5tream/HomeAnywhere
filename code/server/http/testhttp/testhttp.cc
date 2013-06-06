#include <iostream>
#include <stdio.h>

#include "http_server.h"

int testMacro();

int main() {
    
    if (testMacro()) {
        printf("testMacro succeeded\n");
    } else {
        printf("testMacro failed\n");
    }

    return 0;
}

int testMacro() {

    DEBUG("Test DEBUG");
    int i = 0;
    INFO("Test INFO %d", i);
    ERROR("Test ERROR");
    FATAL("Test FATAL");
    return 1;
}



