#include "main.h"

/**
<<<<<<< HEAD
 * _printf - Printf function
 * @format: format
 * @fmt: format
 * @args: argument
 * Return: Printed chars.
 */
int process_format(const char *fmt, va_list args)
=======
 * _printf - printf 
 * @format: format string printed
 * Return: number of characters printed
 */

>>>>>>> refs/remotes/origin/master
int _printf(const char *format, ...)
{
	int chars_printed;
	print_format_t format_list[] = {
		{"%", handle_percent},
		{"d", handle_integer},
		{"i", handle_integer},
		{"c", handle_char},
		{"s", handle_string},
		{"b", handle_binary},
		{"u", handle_unsigned_integer},
		{"o", handle_octal},
		{"x", handle_hex},
		{"X", handle_HEX},
		{"S", handle_String},
		{"p", handle_pointer},
		{"r", handle_rev},
		{"R", handle_rot13},
		{NULL, NULL},
	};
	va_list args;

	if (format == NULL)
		return (-1);

<<<<<<< HEAD
	printed_chars += process_format(format, args);

=======
	va_start(args, format);
	chars_printed = process_format(format, format_list, args);
>>>>>>> refs/remotes/origin/master
	va_end(args);
	return (chars_printed);
}

/**
 * _printf - printf function
 * @format: format
 * Return: number of chars
 */

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int printed_chars = process_format(format, args);

	va_end(args);
	return printed_chars;
}

int main(void)
{
	_printf("%d\n", 98);
	return (0);
}
