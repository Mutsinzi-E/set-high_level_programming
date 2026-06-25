#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Description: prints key/value pairs in array order
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	int first = 1;

	if (!ht)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];

		while (tmp)
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
