#include "main.h"

/**
 * handle_char - Prints character
 * @list: list of arguments
 * Return: return number of characters printed.
 */

int handle_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
