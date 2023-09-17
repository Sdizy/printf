#include "main.h"
#include <stdio.h>

int main() 
{
    const char *message = "Hello, world!";
    char character = 'A';
    int x = 42;
    int y = -123;
    
    int printed_chars = _printf("Message: %s, Character: %c, Percent: %%\n", message, character);
    printf("Message: %s, Character: %c, Percent: %%\n", message, character);
    _printf("Testing integer specifiers: %d, %i\n", x, y);
    printf("Total characters printed: %d\n", printed_chars);

    return 0;
}

