#include "main.h"

/**
 * process_format - Receives main string and parameters, print formated string.
 * @format: A string containing all the desired characters.
 * @format_list: list to functions.
 * @args: arguments passed to the program.
 * Return: number the characters printed.
 */

int process_format(const char *format, print_format_t format_list[], va_list args)
{
	int i, j, r_val, chars_printed;

	chars_printed = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; format_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == format_list[j].sym[0])
				{
					r_val = format_list[j].format(args);
					if (r_val == -1)
						return (-1);
					chars_printed += r_val;
					break;
				}
			}
			if (format_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					chars_printed = chars_printed + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			chars_printed++;
		}
	}
	return (chars_printed);
}
