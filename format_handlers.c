#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**handle characters*/
int handle_char(va_list args)
{
	char c = va_arg(args, int);
	putchar(c);
	return 1;
}

/**handle string*/
int handle_string(va_list args)
{
	const char *str = va_arg(args, const char *);
	if (str != NULL)
	{
		fputs(str, stdout);
		return strlen(str);
	}
	return 6; 
}

/*handle percent*/
int handle_percent(va_list args)
{
	(void)args;
	putchar('%');
	return 1;
}

/** Define a new function to handle unsupported format specifiers*/
int handle_unsupported_specifier(const char *ptr) 
{
    putchar('%');
    putchar(*ptr);
    return 2; 
}

/*for d and i specifiers*/
int handle_int_specifier(va_list args)
{
    int num = va_arg(args, int);

    printf("%d", num);
    return 1;
}
