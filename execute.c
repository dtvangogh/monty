#include "monty.h"
/**
 * runopcode - Runs a given opcode, unless it is invalid
 * @opcode: The opcode to run
 * @line_number: The line number the opcode is on
 */
void execute(char *opcode, unsigned int line_number)
{
	unsigned int i;

	instruction_t opcodes[] = {
		{"pall", pall},
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