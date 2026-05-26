#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to head pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t count = 0;
	listint_t *next;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		temp = *h;
		next = temp->next;

		free(temp);
		count++;

		*h = next;
	}

	return (count);
}
