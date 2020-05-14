#include "monty.h"

/**
 * pall - Prints all items on the stack
 * @stack: Double pointer to the head of the stack
 * @lineNum: The current line numer being processed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void) line_number;
	if (stack == NULL)
		return;
	head = *stack;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}

}
