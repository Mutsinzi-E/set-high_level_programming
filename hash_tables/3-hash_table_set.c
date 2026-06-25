#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int i;
    hash_node_t *tmp, *node;
    char *k, *v;

    if (!ht || !key || !*key || !value)
        return (0);

    i = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[i];

    while (tmp)
    {
        if (!strcmp(tmp->key, key))
        {
            free(tmp->value);
            tmp->value = strdup(value);
            if (!tmp->value)
                return (0);
            return (1);
        }
        tmp = tmp->next;
    }

    node = malloc(sizeof(hash_node_t));
    if (!node)
        return (0);

    k = strdup(key);
    v = strdup(value);

    if (!k || !v)
    {
        free(node);
        if (k)
            free(k);
        if (v)
            free(v);
        return (0);
    }

    node->key = k;
    node->value = v;
    node->next = ht->array[i];
    ht->array[i] = node;

    return (1);
}
