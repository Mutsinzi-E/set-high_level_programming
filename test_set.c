#include <stdio.h>
#include "hash_tables.h"

/**
 * main - test hash_table_set
 */
int main(void)
{
    hash_table_t *ht;

    /* create hash table */
    ht = hash_table_create(1024);

    /* insert values */
    hash_table_set(ht, "name", "Enock");
    hash_table_set(ht, "age", "20");
    hash_table_set(ht, "country", "Rwanda");
    hash_table_set(ht, "language", "C programming");

    /* print pointer (basic check) */
    printf("Hash table created at: %p\n", (void *)ht);

    return (0);
}
