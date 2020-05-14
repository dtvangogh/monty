#include "holberton.h"

/**
 * push - Pushes an item to the top of the stack
 * @num: The number to push
 */
void push(char *number_to_push)
{
	if (number_to_push == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", global.line_number);
		free_list();
		exit(EXIT_FAILURE);
	}
	push_to_list(atoi(number_to_push));
}

/**
 * pushInt - pushes an int to the top of the stack
 * @n: The number to be pushed
 */
void push_to_list(int n)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		free_list();
	}

	new_node->n = n;
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
