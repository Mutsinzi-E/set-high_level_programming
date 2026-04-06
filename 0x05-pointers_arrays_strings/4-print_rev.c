#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: the string to print
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	i--; /* move to last character */
	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
