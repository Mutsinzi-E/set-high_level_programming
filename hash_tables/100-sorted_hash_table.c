#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of array
 *
 * Return: pointer to table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * sorted_insert - inserts node in sorted linked list
 */
static void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	tmp = ht->shead;

	while (tmp && strcmp(tmp->key, node->key) < 0)
		tmp = tmp->snext;

	if (!tmp)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else if (!tmp->sprev)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else
	{
		node->sprev = tmp->sprev;
		node->snext = tmp;
		tmp->sprev->snext = node;
		tmp->sprev = node;
	}
}

/**
 * shash_table_set - adds/updates key/value
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *tmp, *node;
	char *k, *v;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			v = strdup(value);
			if (!v)
				return (0);
			free(tmp->value);
			tmp->value = v;
			return (1);
		}
		tmp = tmp->next;
	}

	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (0);

	k = strdup(key);
	v = strdup(value);
	if (!k || !v)
		return (free(node), free(k), free(v), 0);

	node->key = k;
	node->value = v;
	node->next = ht->array[index];
	node->sprev = NULL;
	node->snext = NULL;

	ht->array[index] = node;
	sorted_insert(ht, node);

	return (1);
}

/**
 * shash_table_get - get value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key || !*key)
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

/**
 * shash_table_print - print in sorted order
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first = 1;

	if (!ht)
		return;

	printf("{");

	tmp = ht->shead;
	while (tmp)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		first = 0;
		tmp = tmp->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - reverse print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first = 1;

	if (!ht)
		return;

	printf("{");

	tmp = ht->stail;
	while (tmp)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		first = 0;
		tmp = tmp->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - free everything
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *next;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = next;
		}
	}

	free(ht->array);
	free(ht);
}
