#include "hash_tables.h"
#include <stdio.h>

int main(void)
{
    shash_table_t *ht;

    ht = shash_table_create(1024);

    shash_table_set(ht, "ALX", "School");

    printf("%s\n", shash_table_get(ht, "ALX"));

    return (0);
}
