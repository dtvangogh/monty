#ifndef HOLBERTON_
#define HOLBERTON_

#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list
 * @n: integer inside element of list
 * @prev: points to previous element of stack
 * @next: points to next element of stack
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct gvar_s - struct for global variables
 * @file: The test file being used
 * @line: The current line being read
 * @line_number: The current line number of test file being read
 * @stack: The stack being used
 */
typedef struct gvar_s
{
	FILE *file;
	int line_number;
	stack_t *head;
	char *line;
	char isStack;
	char *opcode;
} gvar_t;

extern gvar_t global;

void _printerr(char *c);
void openfile(char *name);
void tokenize_and_execute(void);
void execute(char *opcode, unsigned int line_number);
void push(char *number_to_push);
void checkNum(char *str);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void push_to_list(int n);
void free_list(void);
void nop(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);


#endif
