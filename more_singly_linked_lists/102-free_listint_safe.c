#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to pointer to head
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current;
	listint_t *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h)
	{
		current = *h;
		next = current->next;

		/*
		 * detect loop:
		 * if current address becomes greater than next,
		 * stop safely after freeing current node
		 */
		if (current >= next && next != NULL)
		{
			free(current);
			count++;
			break;
		}

		free(current);
		*h = next;
		count++;
	}

	*h = NULL;

	return (count);
}
