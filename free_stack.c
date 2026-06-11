#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: stack head
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
