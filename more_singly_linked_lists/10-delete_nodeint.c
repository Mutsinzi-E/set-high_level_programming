#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes node at index in listint_t list
 * @head: pointer to head pointer
 * @index: index of node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *to_delete;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return (-1);

	to_delete = temp->next;
	temp->next = to_delete->next;
	free(to_delete);

	return (1);
}
