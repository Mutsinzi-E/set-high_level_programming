#include "monty.h"

/**
 * pall_stack - prints all stack values
 * @head: pointer to stack head
 */
void pall_stack(stack_t **head)
{
	stack_t *temp;

	temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
