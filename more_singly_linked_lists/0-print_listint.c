#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to list
 *
 * Return: nothing
 */
void print_listint(const listint_t *h)
{
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
