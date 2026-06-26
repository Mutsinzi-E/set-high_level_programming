#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * create node
 */
static shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
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
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * insert sorted
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *node)
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
		return;
	}

	node->snext = tmp;
	node->sprev = tmp->sprev;

	if (tmp->sprev)
		tmp->sprev->snext = node;
	else
		ht->shead = node;

	tmp->sprev = node;
}

/**
 * shash_table_create
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
 * shash_table_set
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *tmp, *node;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (tmp->value ? 1 : 0);
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
 * shash_table_get
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key)
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
 * shash_table_print
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
 * shash_table_print_rev
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
 * shash_table_delete
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
