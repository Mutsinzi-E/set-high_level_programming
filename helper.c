#include "monty.h"

/**
 * is_number - checks if string is a valid integer
 * @str: input string
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		i++;

	if (str[i] == '\0')
		return (0);

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
