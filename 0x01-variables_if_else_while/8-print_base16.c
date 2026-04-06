#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all numbers of base 16 in lowercase.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
		putchar(c);

	for (c = 'a'; c <= 'f'; c++)
		putchar(c);

	putchar('\n');

	return (0);
}
