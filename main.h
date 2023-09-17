#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**prototype for custom printf
 */
int _printf(const char *format, ...);

#include <string.h>

/** Function prototypes for custom format specifier handlers
 */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int handle_int_specifier(va_list args);

#endif /* MAIN_H */

