#ifndef FLAT_INCLUDES
#define FLAT_INCLUDES
#endif

/** @file log/log.h
    This file provides logging functions
*/

typedef enum log_level log_level;
enum log_level /// Describes the type of message to be sent
{
    LOG_NORMAL, ///< Indicates a normal message
    LOG_ERROR, ///< Indicates an error message
    LOG_DEBUG, ///< Indicates a debug message
};

void _log (log_level level, const char * fmt, ...);

#define plural(singular,plural,count) ( (count) > 1 ? (plural) : (singular) )
/**<
   @brief Evaluates to plural if the given count is greater than 1, or singular otherwise
*/

#define log_error(fmt, ...) _log (LOG_ERROR, "ERROR: " fmt "\n", ##__VA_ARGS__)
/**<
   @brief Printf-like function that prints an error to stderr. A newline is appended to the resulting message
*/

#define log_stderr(fmt, ...) _log (LOG_ERROR, fmt "\n", ##__VA_ARGS__)
/**<
   @brief Printf-like function that prints a message to stderr without prepending ERROR: like log_error does. A newline is appended to the resulting message
*/

#define log_normal(fmt, ...) _log (LOG_NORMAL, fmt "\n", ##__VA_ARGS__)
/**<
   @brief Printf-like function that prints a message to stdout. A newline is appended to the resulting message
*/

#define log_debug(fmt, ...) _log (LOG_DEBUG, "DEBUG: %s: " fmt "\n", __FILE__, ##__VA_ARGS__)
/**<
   @brief Printf-like function that prints a debug message to stderr. A newline is appended to the resulting message
*/

#define log_fatal(fmt, ...) { _log (LOG_ERROR, "FATAL: %s: %s: " fmt "\n", __FILE__, __func__, ##__VA_ARGS__); goto fail; }
/**<
   @brief Printf-like function that prints a fatal error to stderr and then jumps to the 'fail' label. A newline is appended to the resulting message
*/
