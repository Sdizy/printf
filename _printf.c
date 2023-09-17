#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
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
			/**Handle format specifiers*/
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
					/** Unsupported format specifier, just print it*/
					putchar('%');
					putchar(*ptr);
					printed_chars += 2;
			}
		}
	}
	va_end(args);
	return (printed_chars);
}
