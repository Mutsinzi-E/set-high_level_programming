#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Stack struct */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Functions */
void push(stack_t **stack, char *arg, unsigned int line_number);
void pall(stack_t *stack);
void free_stack(stack_t *stack);
void execute(char *opcode, char *arg, stack_t **stack, unsigned int line_number);

#endif
