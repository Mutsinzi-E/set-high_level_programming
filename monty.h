#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list node
 * @n: integer value
 * @prev: previous node
 * @next: next node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* global stack */
extern stack_t *stack;

/* core functions */
void execute(char *line, stack_t **stack, unsigned int line_number);

/* opcodes */
void push_stack(stack_t **head, int n);
void pall_stack(stack_t **head);

/* helpers */
int is_number(char *str);
void free_stack(stack_t *head);

#endif
