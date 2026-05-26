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
	listint_t **seen;
	size_t i = 0, size = 1024;
	listint_t *tmp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	seen = malloc(sizeof(listint_t *) * size);
	if (seen == NULL)
		exit(98);

	while (*h != NULL)
	{
		/* check if already visited */
		for (i = 0; i < count; i++)
		{
			if (seen[i] == *h)
			{
				free(seen);
				*h = NULL;
				return (count);
			}
		}

		/* store node address */
		seen[count] = *h;
		count++;

		/* move and free */
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
	}

	free(seen);
	return (count);
}
