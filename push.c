#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes an element to the stack
 * @value: integer value to push
 * @line_number: line number for error handling
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}
