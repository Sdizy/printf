#include <stdio.h>
#include <stdarg.h>

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

