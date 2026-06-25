#include <stdio.h>
#include "hash_tables.h"

/**
 * main - test hash table
 * Return: 0
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	if (!ht)
		return (1);

	printf("name: %s\n",
		hash_table_get(ht, "name"));

	printf("age: %s\n",
		hash_table_get(ht, "age"));

	printf("school: %s\n",
		hash_table_get(ht, "school"));

	hash_table_set(ht, "name", "Enock");
	hash_table_set(ht, "age", "20");
	hash_table_set(ht, "school", "ALU");

	hash_table_print(ht);

	hash_table_delete(ht);

	return (0);
}
