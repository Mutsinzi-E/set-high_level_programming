#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers (0 to 9)
 *              followed by a new line.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		putchar(i + '0');

	putchar('\n');

	return (0);
}
