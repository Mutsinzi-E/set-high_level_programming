#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to head pointer
 *
 * Return: pointer to new head
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev;
	listint_t *current;

	if (head == NULL || *head == NULL)
		return (NULL);

	prev = NULL;
	current = *head;

	while (current)
	{
		*head = current->next;
		current->next = prev;
		prev = current;
		current = *head;
	}

	return (prev);
}
