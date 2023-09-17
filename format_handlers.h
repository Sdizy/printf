#include "main.h"

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

/*for d and i specifiers*/

#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int handle_int_specifier(va_list args)
{
    int num = va_arg(args, int);

    printf("%d", num);
    return 1;
}
