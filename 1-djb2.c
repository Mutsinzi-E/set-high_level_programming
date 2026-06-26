#include "hash_tables.h"

/**
 * djb2 - hash function
 * @str: string input
 * Return: hash value
 */
unsigned long int djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
