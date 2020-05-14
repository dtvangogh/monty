#include "monty.h"
/**
 * pint - pprint the top of the stack
 * @head: pointer to doubly link list
 * @l: line number
 *
 */
void pint(stack_t **head, unsigned int line_number)
{

	if (!*head)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}