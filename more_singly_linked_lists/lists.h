#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: pointer to next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* REQUIRED PROTOTYPES */

listint_t *add_nodeint_end(listint_t **head, const int n);
void print_listint(const listint_t *h);
int pop_listint(listint_t **head);
void free_listint2(listint_t **head);

#endif
