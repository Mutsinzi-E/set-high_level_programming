#include "hash_tables.h"
#include <stdlib.h>

/**
 * shash_table_delete - frees table
 * @ht: hash table
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
