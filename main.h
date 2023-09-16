#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int numlen(int n);
int numlen_unsigned(unsigned int n);
int print_binary(unsigned int n);

#endif /* MAIN_H */

