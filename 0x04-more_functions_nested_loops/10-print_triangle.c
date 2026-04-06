#include "main.h"

/**
 * print_triangle - prints a triangle using the # character
 * @size: the size of the triangle
 *
 * Description: prints a right-aligned triangle of '#' characters
 *              followed by a new line. If size <= 0, prints only a newline.
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* print spaces */
		for (j = 1; j <= size - i; j++)
			_putchar(' ');

		/* print # characters */
		for (j = 1; j <= i; j++)
			_putchar('#');

		_putchar('\n');
	}
}
