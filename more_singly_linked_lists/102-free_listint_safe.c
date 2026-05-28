#include "lists.h"
#include <stdlib.h>

/**
 * loop_len - counts unique nodes in a looped list
 * @head: pointer to head
 *
 * Return: number of unique nodes, 0 if no loop
 */
size_t loop_len(listint_t *head)
{
	listint_t *slow, *fast;
	size_t count = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = (head->next)->next;

	while (fast && fast->next)
	{
		if (slow == fast)
		{
			slow = head;

			while (slow != fast)
			{
				count++;
				slow = slow->next;
				fast = fast->next;
			}

			slow = slow->next;

			while (slow != fast)
			{
				count++;
				slow = slow->next;
			}

			return (count);
		}

		slow = slow->next;
		fast = (fast->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to pointer to head
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t nodes, i;

	if (h == NULL || *h == NULL)
		return (0);

	nodes = loop_len(*h);

	if (nodes == 0)
	{
		for (i = 0; *h != NULL; i++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}
	else
	{
		for (i = 0; i < nodes; i++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

		*h = NULL;
	}

	h = NULL;

	return (i);
}
