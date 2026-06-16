#include "monty.h"

void execute(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    if (strcmp(opcode, "push") == 0)
        push(stack, arg, line_number);

    else if (strcmp(opcode, "pall") == 0)
        pall(*stack);

    else if (opcode[0] == '\0')
        return;

    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}
