#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - adds or updates key/value pair
 * @ht: hash table
 * @key: key string
 * @value: value string
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	hash_node_t *tmp, *new;
	char *k, *v;

	if (!ht || !key || !*key || !value)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[i];

	while (tmp && strcmp(tmp->key, key))
		tmp = tmp->next;

	if (tmp)
	{
		v = strdup(value);
		if (!v)
			return (0);
		free(tmp->value);
		tmp->value = v;
		return (1);
	}

	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (0);

	k = strdup(key);
	v = strdup(value);
	if (!k || !v)
		return (free(new), free(k), free(v), 0);

	new->key = k;
	new->value = v;
	new->next = ht->array[i];
	ht->array[i] = new;

	return (1);
}
