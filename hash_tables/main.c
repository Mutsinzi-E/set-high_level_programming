#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
	char *key = "school";
	unsigned long int size = 1024;

	printf("%lu\n", key_index((unsigned char *)key, size));

	return (0);
}
