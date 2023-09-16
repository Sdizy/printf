#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;

 va_start(args, format);

while (*format)
{
if (*format != '%')
{
putchar(*format);
printed_chars++;
}
else
{
format++;

if (*format == 'c')
{
char c = va_arg(args, int);
putchar(c);
printed_chars++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
putchar(*str);
printed_chars++;
str++;
}
}
else if (*format == '%')
{
putchar('%');
printed_chars++;
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
printf("%d", num);
printed_chars += numlen(num);
}
format++;
}
}

va_end(args);
return (printed_chars);
}
