#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int c = 0;

	va_list args;
	va_start(args, format);
	
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			c++;
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
				c++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				while (*str)
				{
					putchar(*str);
					str++;
					c++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				c++;
			}
			else
			{

				putchar('%');
				c++;
				format--;
			}
		}
		format++;
	}
	
	va_end(args);
	return (c);
}
