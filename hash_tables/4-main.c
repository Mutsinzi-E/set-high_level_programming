#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check hash_table_get
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	hash_table_t *ht;
	char *value;

	ht = hash_table_create(1024);

	hash_table_set(ht, "c", "fun");
	hash_table_set(ht, "python", "awesome");
	hash_table_set(ht, "Bob", "and Kris love asm");
	hash_table_set(ht, "N", "queens");

	value = hash_table_get(ht, "python");
	printf("python:%s\n", value);

	value = hash_table_get(ht, "Bob");
	printf("Bob:%s\n", value);

	value = hash_table_get(ht, "N");
	printf("N:%s\n", value);

	value = hash_table_get(ht, "javascript");
	printf("javascript:%s\n", value);

	return (EXIT_SUCCESS);
}
