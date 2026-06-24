#include "hash_tables.h"

/**
 * key_index - gives index for a key
 * @key: the key
 * @size: size of hash table array
 *
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash;

    hash = hash_djb2(key);

    return (hash % size);
}
