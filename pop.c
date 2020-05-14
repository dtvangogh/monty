#include "monty.h"
/**
 * pop - remove the head
 * @head: pointer to doubly link list
 * Return: pointer to the node or NULL
 */
void pop(stack_t **head, unsigned int line_number)
{

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
}