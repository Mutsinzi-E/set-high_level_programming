#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to previous element
 * @next: points to next element
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void push_stack(stack_t **head, int n);
void pall_stack(stack_t **head);
void execute(char *line, stack_t **stack, unsigned int line_number);
int is_number(char *str);

#endif
