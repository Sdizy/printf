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

/*To handle d and i specifiers*/
int handle()
{
    int x = 42;
    int y = -123;

    _printf("Testing integer specifiers: %d, %i\n", x, y);

    return 0;
}
