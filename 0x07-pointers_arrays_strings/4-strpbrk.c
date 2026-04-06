#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: string containing bytes to search for
 *
 * Return: pointer to first occurrence in s of any byte in accept
 *         or NULL if no byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}

	return (0);
}
