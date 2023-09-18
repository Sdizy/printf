#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define NUL '\0'

/**
 * struct convert - defines a structure for symbols and functions
 *
 * @sym: The operator
 * @format: The function associated
 */

struct convert
{
	char *sym;
	int (*format)(va_list);
};
typedef struct convert print_format_t;


int _printf(const char *format, ...);
int _putchar(char c);
int process_format(const char *format, print_format_t format_list[], va_list args);
int handle_percent(va_list);
int handle_integer(va_list);
int handle_char(va_list);
int handle_string(va_list);
int handle_binary(va_list);
int handle_unsigned_integer(va_list);
int handle_octal(va_list list);
int handle_hex(va_list list);
int handle_HEX(va_list list);
int handle_String(va_list val);
int handle_pointer(va_list val);
int handle_rev(va_list l);
int handle_rot13(va_list list);

int handle_number(va_list args);
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int handle_unsgined_number(unsigned int n);
int hex_check(int num, char x);
int handle_hex_aux(unsigned long int num);
int isNonAlphaNumeric(char c); 
int _puts(char *str);
char *convert(unsigned long int num, int base, int lowercase);
#endif
