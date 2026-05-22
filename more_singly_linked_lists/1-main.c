#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main(void)
{
	listint_t hello = {8, NULL};
	listint_t *head = &hello;
	listint_t *new;
	size_t n;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (1);

	new->n = 9;
	new->next = head;
	head = new;

	n = listint_len(head);

	printf("-> %lu elements\n", n);

	free(new);

	return (0);
}
