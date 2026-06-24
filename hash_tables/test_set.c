#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);

    hash_table_set(ht, "name", "Enock");
    hash_table_set(ht, "age", "20");
    hash_table_set(ht, "country", "Rwanda");

    printf("OK\n");

    return (0);
}
