#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * create_node - creates node
 */
static shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

	if (!node)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);

	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->snext = NULL;
	node->sprev = NULL;

	return (node);
}

/**
 * shash_table_create - creates table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * insert_sorted - inserts node in sorted list
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *curr;

	if (!ht->shead)
	{
		ht->shead = ht->stail = node;
		return;
	}

	curr = ht->shead;

	while (curr && strcmp(node->key, curr->key) > 0)
		curr = curr->snext;

	if (curr == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}

	if (!curr)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
		return;
	}

	node->snext = curr;
	node->sprev = curr->sprev;
	curr->sprev->snext = node;
	curr->sprev = node;
}

/**
 * shash_table_set - adds or updates key/value
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *tmp, *node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			char *new_value = strdup(value);

			if (!new_value)
				return (0);

			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}

	node = create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	insert_sorted(ht, node);

	return (1);
}

/**
 * shash_table_get - get value
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

/**
 * shash_table_print - print sorted
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
 * shash_table_print_rev - print reverse
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
 * shash_table_delete - free memory
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *next;

	if (!ht)
		return;

	tmp = ht->shead;

	while (tmp)
	{
		next = tmp->snext;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = next;
	}

	free(ht->array);
	free(ht);
}
