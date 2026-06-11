#include "monty.h"

/**
 * execute - executes Monty bytecode instructions
 * @line: input line
 * @stack: stack head
 * @line_number: line number
 */
void execute(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	char *value;

	opcode = strtok(line, " \t\n");

	/* ✅ ignore empty lines */
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, " \t\n");

		if (value == NULL || !is_number(value))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		push_stack(stack, atoi(value));
		return;
	}

	if (strcmp(opcode, "pall") == 0)
	{
		pall_stack(stack);
		return;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
