#include "lists.h"
#include <stdlib.h>

/**
 * free_looped_list - frees looped linked list
 * @h: pointer to head
 * @loop: start of loop
 *
 * Return: number of nodes freed
 */
size_t free_looped_list(listint_t **h, listint_t *loop)
{
	listint_t *tmp;
	size_t count = 0;

	while (*h != loop)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	tmp = loop->next;
	free(loop);
	count++;

	while (tmp != loop)
	{
		loop = tmp->next;
		free(tmp);
		tmp = loop;
		count++;
	}

	return (count);
}

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to pointer to head
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
		{
			slow = *h;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			count = free_looped_list(h, slow);
			*h = NULL;
			return (count);
		}
	}

	while (*h)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	return (count);
}
