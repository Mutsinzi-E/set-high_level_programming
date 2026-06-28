#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_node - creates a new shash node
 * @key: key string
 * @value: value string
 *
 * Return: new node or NULL
 */
static shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);

	node->next = NULL;
	node->snext = NULL;
	node->sprev = NULL;

	return (node);
}

/**
 * sorted_insert - inserts node into sorted list
 * @ht: hash table
 * @node: node to insert
 */
static void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (!ht->shead)
	{
		ht->shead = ht->stail = node;
		return;
	}

	tmp = ht->shead;

	while (tmp && strcmp(node->key, tmp->key) > 0)
		tmp = tmp->snext;

	if (!tmp)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
		return;
	}

	if (tmp == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}

	node->snext = tmp;
	node->sprev = tmp->sprev;
	tmp->sprev->snext = node;
	tmp->sprev = node;
}

/**
 * shash_table_set - adds key/value pair to table
 * @ht: hash table
 * @key: key string
 * @value: value string
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *tmp;

	if (!ht || !key || !value || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}

	node = create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	sorted_insert(ht, node);

	return (1);
}
