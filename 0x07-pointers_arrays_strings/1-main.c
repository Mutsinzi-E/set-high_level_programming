#include "main.h"
#include <stdio.h>

int main(void)
{
    char src[] = "Hello, World!";
    char dest[20];

    _memcpy(dest, src, 13);  /* copy 13 bytes */
    dest[13] = '\0';          /* add null terminator */
    printf("%s\n", dest);
    return (0);
}
