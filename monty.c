#include "monty.h"
gvar_t global;

/**
 * main - Main function the program enters in
 * @argc: The number of arguments passed to the program
 * @argv: Pointer to array of pointers each pointing to an argument passed to
 * the program
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	global.head = NULL;
	global.line = NULL;
	global.isStack = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global.file = file;

	tokenize_and_execute();
	free_list();
	return (0);
}

/**
 * process - processes the monty file line by line
 */
void tokenize_and_execute(void)
{
	ssize_t read;
	size_t len = 0;
	char *opcode;
	char *isolate_number;

	while ((read = getline(&global.line, &len, global.file)) != -1)
	{
		global.line_number++;
		isolate_number = strtok(global.line, "push \t\n");

		opcode = strtok(global.line, " \t\n");
		printf("opcode is:%s\n", &*opcode);
		if (!opcode || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
				push(isolate_number);
		else
			execute(opcode, global.line_number);

	}
}



/**
 * cleanup - Function to clean up stack and file
 */
void free_list(void)
{
	stack_t *item;

	while (global.head)
	{
		item = global.head->next;
		free(global.head);
		global.head = item;
	}

	free(global.line);

	fclose(global.file);
}
