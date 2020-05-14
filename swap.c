#include "monty.h"

/**
 * stk_swap - swaps first two elements on the stack
 * @head: head
 * @ln: line number where opcode is located
 */

void swap(stack_t **head, unsigned int line_number)
{
	stack_t *t1, *t2;

	int t1_number;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		return;
	}
	t1 = (*head);
	t2 = t1->next;
	t1_number = t1->n;
	t1->n = t2->n;
	t2->n = t1_number;
}