#define MESSAGE_SIZE 500

/**
 * @brief Enumération permettant de définir les différents niveaux de log
 * */
typedef enum logLevel{traceLvl, debugLvl, infoLvl, warnLvl, errorLvl, fatalLvl, none} logLevel;

/**
 * @brief Permet de définir le niveau de log utilisé
 * @param level le niveau de log a utiliser
 * */
void setLoggerLevel(char* level);

/**
 * @brief Ajoute un log
 * @param level le niveau du log à ajouter
 * @param message le message du log à ajouter
 * */
void addLog(logLevel level, char* message);

/**
 * @brief Ajoute un log du niveau trace
 * */
void trace(const char *fmt, ...);

/**
 * @brief Ajoute un log du niveau debug
 * */
void debug(const char *fmt, ...);

/**
 * @brief Ajoute un log du niveau info
 * */
void info(const char *fmt, ...);

/**
 * @brief Ajoute un log du niveau warn
 * */
void warn(const char *fmt, ...);

/**
 * @brief Ajoute un log du niveau error
 * */
void error(const char *fmt, ...);

/**
 * @brief Ajoute un log du niveau fatal
 * */
void fatal(const char *fmt, ...);

/**
 * @brief Affiche un log
 * @param level le niveau du log à afficher
 * @param message le messsage du log à afficher
 * */
void printLog(logLevel level, char* message);

// Tests
void loggerTests();
