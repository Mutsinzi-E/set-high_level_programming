#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: string containing characters to match
 *
 * Return: number of bytes in the initial segment of s
 *         which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	int j, found;

	while (s[i])
	{
		found = 0;
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		i++;
	}
	return (i);
}
