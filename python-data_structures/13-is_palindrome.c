#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: head node
 *
 * Return: reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - checks if linked list is palindrome
 * @head: pointer to head pointer
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *second;
	listint_t *copy;
	listint_t *current;

	if (head == NULL || *head == NULL)
		return (1);

	slow = *head;
	fast = *head;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	second = reverse_list(slow->next);
	copy = second;

	current = *head;

	while (second != NULL)
	{
		if (current->n != second->n)
		{
			reverse_list(copy);
			return (0);
		}

		current = current->next;
		second = second->next;
	}

	reverse_list(copy);

	return (1);
}
