#include "hash_tables.h"

/**
 * key_index - returns index for a key
 * @key: the key string
 * @size: size of hash table
 * Return: index position
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);
	return (hash % size);
}
