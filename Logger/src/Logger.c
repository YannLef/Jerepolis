#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "string.h"

#include "../../BetterTerminal/headers/BetterTerminal.h"

#include "../headers/Logger.h"

extern logLevel loggerLevel;

void setLoggerLevel(char* level){
	if(strcmp(level, "trace") == 0){
		loggerLevel = traceLvl;
	}
	if(strcmp(level, "debug") == 0){
		loggerLevel = debugLvl;
	}
	if(strcmp(level, "info") == 0){
		loggerLevel = infoLvl;
	}
	if(strcmp(level, "warn") == 0){
		loggerLevel = warnLvl;
	}
	if(strcmp(level, "error") == 0){
		loggerLevel = errorLvl;
	}
	if(strcmp(level, "fatal") == 0){
		loggerLevel = fatalLvl;
	}
	if(strcmp(level, "none") == 0){
		loggerLevel = none;
	}
}

void addLog(logLevel level, char* message){
	// Add Trace
	if(loggerLevel == traceLvl){
		if(level >= traceLvl){
			printLog(level, message);
		}
	}
	
	// Add Debug
	if(loggerLevel == debugLvl){
		if(level >= debugLvl){
			printLog(level, message);
		}
	}
	
	// Add Info
	if(loggerLevel == infoLvl){
		if(level >= infoLvl){
			printLog(level, message);
		}
	}
	
	// Add Warn
	if(loggerLevel == warnLvl){
		if(level >= warnLvl){
			printLog(level, message);
		}
	}
	
	//Add Error
	if(loggerLevel == errorLvl){
		if(level >= errorLvl){
			printLog(level, message);
		}
	}
	
	// Add Fatal
	if(loggerLevel == fatalLvl){
		if(level >= fatalLvl){
			printLog(level, message);
		}
	}
}

void trace(const char *fmt, ...){
	char string[MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    addLog(traceLvl, string);
}

void debug(const char *fmt, ...){
	char string[MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    addLog(debugLvl, string);
}

void info(const char *fmt, ...){
	char string[MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    addLog(infoLvl, string);
}

void warn(const char *fmt, ...){
	char string[MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    addLog(warnLvl, string);
}

void error(const char *fmt, ...){
	char string[MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    addLog(errorLvl, string);
}

void fatal(const char *fmt, ...){
	char string[MESSAGE_SIZE];
	va_list args;
    va_start(args, fmt);
    vsprintf(string, fmt, args);
    va_end(args);
    
    addLog(fatalLvl, string);
}

void printLog(logLevel level, char* message){
	if(level == traceLvl){
		printf("[Trace] %s\n", message);
	}
	if(level == debugLvl){
		printf(GRN "[Debug] " RESET "%s\n", message);
	}
	if(level == infoLvl){
		printf(CYN "[Info] " RESET "%s\n", message);
	}
	if(level == warnLvl){
		printf(BLU "[Warn] " RESET "%s\n", message);
	}
	if(level == errorLvl){
		printf(YEL "[Error] " RESET "%s\n", message);
	}
	if(level == fatalLvl){
		printf(RED "[Fatal] " RESET "%s\n", message);
	}
}

// Tests

void loggerTests(){
	setLoggerLevel("debug"); // Default
	
	trace("My Trace Message");
	debug("My Debug Message");
	info("My Info Message");
	warn("My Warn Message");
	error("My Error Message");
	fatal("My Fatal Message");
}
