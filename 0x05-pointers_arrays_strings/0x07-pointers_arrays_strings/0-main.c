#include <stdio.h>
#include "main.h"

int main(void)
{
    char buffer[50] = "Talk is cheap. Show me the code.";
    _memset(buffer, 0x20, 16);

    printf("%s\n", buffer);
    return 0;
}
