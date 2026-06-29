#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to head pointer
 *
 * Return: pointer to new head
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current;
	listint_t *next;

	if (head == NULL)
		return (NULL);

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}
