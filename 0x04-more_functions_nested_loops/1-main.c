#include "main.h"
#include <stdio.h>

/**
 * main - check _isdigit function
 *
 * Return: 0
 */
int main(void)
{
    char c;

    for (c = '0'; c <= '9'; c++)
        printf("%c: %d\n", c, _isdigit(c));
    for (c = 'a'; c <= 'z'; c++)
        printf("%c: %d\n", c, _isdigit(c));
    return (0);
}
