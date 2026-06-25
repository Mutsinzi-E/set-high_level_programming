#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the hash_table_set function
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);

	hash_table_set(ht, "betty", "cool");
	hash_table_set(ht, "school", "alu");
	hash_table_set(ht, "language", "C");
	hash_table_set(ht, "country", "Rwanda");

	printf("betty: %s\n", hash_table_get(ht, "betty"));
	printf("school: %s\n", hash_table_get(ht, "school"));
	printf("language: %s\n", hash_table_get(ht, "language"));
	printf("country: %s\n", hash_table_get(ht, "country"));

	return (EXIT_SUCCESS);
}
