#define MESSAGE_SIZE 500

typedef enum logLevel{traceLvl, debugLvl, infoLvl, warnLvl, errorLvl, fatalLvl, none} logLevel;

void setLoggerLevel(char* level);
void addLog(logLevel level, char* message);
void trace(const char *fmt, ...);
void debug(const char *fmt, ...);
void info(const char *fmt, ...);
void warn(const char *fmt, ...);
void error(const char *fmt, ...);
void fatal(const char *fmt, ...);
void printLog(logLevel level, char* message);

// Tests
void loggerTests();
