#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

extern stack_t *stack;

void push(stack_t **stack, int n);
void pall(stack_t **stack);
void execute(char *line, stack_t **stack, unsigned int line_number);
int is_number(char *str);

#endif
