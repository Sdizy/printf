#include "main.h"

int main() 
{
    const char *message = "Hello, world!";
    char character = 'A';

    int printed_chars = _printf("Message: %s, Character: %c, Percent: %%\n", message, character);
    printf("Message: %s, Character: %c, Percent: %%\n", message, character);

    _printf("Total characters printed: %d\n", printed_chars);
    printf("Total characters printed: %d\n", printed_chars);

    return 0;
}

