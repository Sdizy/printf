#include "main.h"

/**
 * _printf - printf 
 * @format: format string printed
 * Return: number of characters printed
 */

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

	va_start(args, format);
	chars_printed = process_format(format, format_list, args);
	va_end(args);
	return (chars_printed);
}
