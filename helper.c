#include "monty.h"

/**
 * is_number - checks if string is an integer
 * @str: string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
