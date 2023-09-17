#include "main.h"
/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	const char *ptr;
	int printed_chars = 0;

	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			putchar(*ptr);
			printed_chars++;
		}
		else
		{
			ptr++;
			switch (*ptr)
			{
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
					putchar('%');
					putchar(*ptr);
					printed_chars += 2;
			}
		}
	}
	va_end(args);
	return (printed_chars);
}

/*Handling the d and i specidiers*/

#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
	int printed_chars = 0;
	const char *ptr;
	va_list args;
	va_start(args, format);

	for (ptr = format; ptr; ptr++)
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
			else if (*ptr == 'd' || *ptr == 'i')
			{
				printed_chars += handle_int_specifier(args);
			}
			else
			{
				putchar('%');
				putchar(*ptr);
				printed_chars += 2;
			}
		}
	}
	va_end(args);
	return printed_chars;
}
