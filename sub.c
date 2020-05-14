#include "monty.h"

void sub(stack_t **head, unsigned int line_number)
{
	int t1_value;
	int t2_value;
	int subtract;
	stack_t *temp;
	stack_t *temp2;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (head == NULL || (*head) == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	temp = (*head);
	temp2 = temp->next;
	t1_value = temp->n;
	t2_value = temp2->n;
	subtract = t1_value - t2_value;
	if (subtract < 0)
		subtract = subtract * -1;

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

	new_node->n = subtract;
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