#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list node
 * @n: integer stored in the node
 * @next: pointer to next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* function prototype */
size_t listint_len(const listint_t *h);

#endif
