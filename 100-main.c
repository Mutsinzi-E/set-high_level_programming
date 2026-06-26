#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the sorted hash table
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	shash_table_t *ht;

	ht = shash_table_create(1024);

	shash_table_set(ht, "y", "0");
	shash_table_set(ht, "j", "1");
	shash_table_set(ht, "c", "2");
	shash_table_set(ht, "b", "3");
	shash_table_set(ht, "z", "4");
	shash_table_set(ht, "n", "5");
	shash_table_set(ht, "a", "6");
	shash_table_set(ht, "m", "7");

	printf("\n--- PRINT (SORTED) ---\n");
	shash_table_print(ht);

	printf("\n--- PRINT REVERSE ---\n");
	shash_table_print_rev(ht);

	printf("\n--- GET TEST ---\n");
	printf("Key 'c': %s\n", shash_table_get(ht, "c"));
	printf("Key 'z': %s\n", shash_table_get(ht, "z"));
	printf("Key 'a': %s\n", shash_table_get(ht, "a"));

	printf("\n--- UPDATE TEST ---\n");
	shash_table_set(ht, "ALX", "is cool");
	shash_table_set(ht, "ALX", "is soooo cool");
	shash_table_set(ht, "ALX", "is awesome");

	shash_table_print(ht);

	printf("\n--- NULL SAFETY TEST ---\n");
	shash_table_set(NULL, "A", "B");
	shash_table_get(NULL, "A");
	shash_table_print(NULL);
	shash_table_print_rev(NULL);

	shash_table_delete(ht);

	return (EXIT_SUCCESS);
}
