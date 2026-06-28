#include "hash_tables.h"
#include <string.h>

/**
 * shash_table_get - get value by key
 * @ht: hash table
 * @key: key
 *
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}
