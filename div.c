#include "monty.h"

void op_div(stack_t **head, unsigned int line_number)
{
	int t1_value;
	int t2_value;
	int quotient;
	stack_t *temp;
	stack_t *temp2;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	temp = (*head);
	temp2 = temp->next;
	t1_value = temp->n;
	t2_value = temp2->n;
	quotient = t1_value / t2_value;

	temp = (*head); /** answer correct without temp, but memory errors without it **/
	*head = (*head)->next;
	free(temp);
	if (*head != NULL)
		(*head)->prev = NULL;

	temp2 = (*head); /** answer correct without temp, but memory errors without it **/
	*head = (*head)->next;
	free(temp2);
	if (*head != NULL)
		(*head)->prev = NULL;

	new_node->n = quotient;
	new_node->prev = NULL;

	if (global.head == NULL)
	{
		new_node->next = NULL;
		global.head = new_node;
	}
	else
	{
			new_node->next = global.head;
			global.head->prev = new_node;
			global.head = new_node;
		}
}