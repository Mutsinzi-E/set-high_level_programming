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
	listint_t *slow, *fast, *tmp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	slow = *h;

	while (slow)
	{
		tmp = slow->next;
		free(slow);
		count++;

		if (slow == fast)
			break;

		slow = tmp;
	}

	*h = NULL;

	return (count);
}
