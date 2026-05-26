#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current, *temp;
	size_t count = 0;

	current = head;

	while (current)
	{
		temp = head;

		while (temp != current)
		{
			if (temp == current->next)
			{
				printf("-> [%p] %d\n",
					(void *)current->next,
					current->next->n);
				return (count);
			}

			temp = temp->next;
		}

		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	}

	return (count);
}
