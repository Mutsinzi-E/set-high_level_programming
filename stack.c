#include "monty.h"

/* PUSH - add node to top of stack */
void push(stack_t **stack, char *arg, unsigned int line_number)
{
    int i;

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* validate integer */
    for (i = 0; arg[i]; i++)
    {
        if (arg[i] == '-' && i == 0)
            continue;
        if (!isdigit(arg[i]))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    int value = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
        exit(EXIT_FAILURE);

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/* PALL - print all stack values from top */
void pall(stack_t *stack)
{
    stack_t *temp = stack;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/* FREE STACK - clean memory */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
