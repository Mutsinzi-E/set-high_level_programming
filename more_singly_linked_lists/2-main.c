#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main(void)
{
	listint_t *head = NULL;

	add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);

	print_listint(head);

	return (0);
}
