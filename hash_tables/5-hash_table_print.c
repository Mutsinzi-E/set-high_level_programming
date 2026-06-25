#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
 *
 * Description: keys/values are printed in the order they appear in the array
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];

		while (tmp != NULL)
		{
			if (!first)
				printf(", ");

			printf("'%s': '%s'", tmp->key, tmp->value);
			first = 0;

			tmp = tmp->next;
		}
	}

	printf("}\n");
}
