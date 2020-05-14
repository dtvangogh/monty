#include "monty.h"
/**
 * pop - remove the head
 * @head: pointer to doubly link list
 * Return: pointer to the node or NULL
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}

	temp = (*head); /** answer correct without temp, but memory errors without it **/
	*head = (*head)->next;
	free(temp);
	if (*head != NULL)
		(*head)->prev = NULL;
}