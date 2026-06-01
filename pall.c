#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
