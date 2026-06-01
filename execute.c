#include "monty.h"
#include <string.h>

void execute(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	char *value;

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, " \t\n");
		if (!value || is_number(value) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(value));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
