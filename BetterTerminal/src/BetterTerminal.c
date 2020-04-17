#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "../headers/BetterTerminal.h"

void println(const char *fmt, ...){
	char string[PRINTLN_MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    printf("%s\n", string);
}
