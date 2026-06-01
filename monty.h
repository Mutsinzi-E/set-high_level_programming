#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, int value);
void pall(stack_t **stack);

#endif
