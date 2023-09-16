#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int count = 0;
	int i;

	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;

				if (*format == '\0')
				{
					break;

				}
				else if (*format == 'c')
				{
					char c = va_arg(args, int);
					putchar(c);
					count++;
				}
				else if (*format == 's')
				{
					char *str = va_arg(args, char*);
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
				}
				else if (*format == 'd' || *format == 'i')
				{
					int num = va_arg(args, int);
					printf("%d", num);
					count++;
					while (num != 0)
					{
						num /= 10;
						count++;
					}
				}
				else if (*format == 'b')
				{
					unsigned int num = va_arg(args, unsigned int);
					int binary[32];
					int index = 0;

					for (i = 31; i >= 0; i--)
					{
						binary[index] = (num >> i) & 1;
						index++;
					}
					for (i = 0; i < 32; i++)
					{
						putchar('0' + binary[i]);
						count++;
					}
				}
				else if (*format == '%')
				{
					putchar('%');
					count++;
				}
				else
				{
					putchar('%');
					count++;
					format--;
				}
		}
		format++;
	}
	va_end(args);
	return count;
}
