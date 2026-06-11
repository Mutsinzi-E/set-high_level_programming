#include "monty.h"

/**
 * execute - executes monty instructions
 * @line: current line
 * @stack: stack head
 * @line_number: current line number
 */
void execute(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	char *value;

	opcode = strtok(line, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, " \t\n");

		if (value == NULL || !is_number(value))
		{
			fprintf(stderr,
				"L%u: usage: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}

		push_stack(stack, atoi(value));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall_stack(stack);
	}
	else
	{
		fprintf(stderr,
			"L%u: unknown instruction %s\n",
			line_number,
			opcode);
		exit(EXIT_FAILURE);
	}
}
