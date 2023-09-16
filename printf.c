<<<<<<< HEAD
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
=======
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters written
 */

int _printf(const char *format, ...)
{
int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; 
	    switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    printed_chars++;
                    break;

                case 's':
                    printed_chars += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    putchar('%');
                    printed_chars++;
                    break;

                default:
                    putchar('%'); 
                    putchar(*format);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++; 
    }

    va_end(args);
    return printed_chars;
}

int main()
{
    int count = _printf("Hello, %s! This is a %c example: %%.\n", "world", 'C');
    printf("\nTotal characters printed: %d\n", count);
    return 0;
}

>>>>>>> 1db954db222c2f3f7b4cec5b8139db3e8178313c
