#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *head;
	listint_t *node;

	head = NULL;

	add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	add_nodeint(&head, 4);
	add_nodeint(&head, 98);
	add_nodeint(&head, 402);
	add_nodeint(&head, 1024);

	print_listint_safe(head);

	/* create a loop */
	node = add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);

	node->next = add_nodeint(&head, 98);

	print_listint_safe(head);

	return (0);
}
