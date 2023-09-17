#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Printf function
 * @format: format
 * @args: argument
 * Return: Printed chars.
 */
int process_format(const char *fmt, va_list args);
int _printf(const char *format, ...)
{
	int printed_chars = 0;

	va_list args;

	va_start(args, format);

	printed_chars += process_format(format, args);
	
	va_end(args);
	return (printed_chars);
}

/**
 * process_format - format function called
 * @fmt: format called
 */
int process_format(const char *fmt, va_list args)
{
	const char *ptr;
	int printed_chars = 0;

	for (ptr = fmt; *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			putchar(*ptr);
			printed_chars++;
		}
		else
		{
			ptr++;
			if (*ptr == '\0')
			{
				break;
			}
			else
			{
			switch (*ptr)
			{
				case 'd':
				case 'i':
					printed_chars += handle_int_specifier(args);
					break;
				case 'c':
					printed_chars += handle_char(args);
					break;
				case 's':
					printed_chars += handle_string(args);
					break;
				case '%':
					printed_chars += handle_percent(args);
					break;
				default:
					printed_chars += handle_unsupported_specifier(ptr);
					break;
			}
			}
		}
	}
	return (printed_chars);
}
