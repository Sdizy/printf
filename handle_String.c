#include "main.h"

/**
 * handle_string - Prints a string
 * @list: list of arguments
 * Return: return the number of characters printed.
 */

int handle_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
