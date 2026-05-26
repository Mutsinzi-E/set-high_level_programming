#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - frees a listint_t list safely (loop safe)
 * @h: pointer to head pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *node;
	size_t count = 0;
	listint_t *tmp;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		node = *h;
		tmp = node->next;

		/* break loop safely: if node already seen, stop */
		if (node == tmp)
		{
			free(node);
			count++;
			*h = NULL;
			return (count);
		}

		free(node);
		count++;
		*h = tmp;
	}

	*h = NULL;
	return (count);
}
