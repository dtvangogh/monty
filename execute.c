#include "monty.h"
/**
 * execute - executes function
 * @opcode: The opcode
 * @line_number: The line number the opcode is found
 */
void execute(char *opcode, unsigned int line_number)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", op_div},
		{"mul", mul},
		{"mod", mod},

		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; ++i)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(&global.head, line_number);
			return;
		}
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, opcode);
	free_list();
	exit(EXIT_FAILURE);
}