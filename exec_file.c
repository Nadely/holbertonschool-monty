#include "monty.h"

/**
 * find_file - Use the path to know which function use
 *
 * @file: path of file to execute cmd
 * @stack: header of the stack
 *
 * Return: void
 */
void find_file(FILE *file, stack_t **stack)
{
	char *command, *buffer = NULL;
	size_t n;
	unsigned int counter_line = 1;

	global.file = file;

	while (getline(&buffer, &n, file) != -1)
	{
		global.buffer = buffer;
		command = strtok(buffer, " \n\t\r");
		if (command)
			execute_cmd(stack, counter_line, command);
		counter_line++;
	}

	free(buffer);
}

/**
 * execute_cmd - execute the right command
 *
 * @stack: the head of the stack
 * @counter_line: number of line of execute cmd
 * @command: the command to execute
 *
 * Return: Void
 */
void execute_cmd(stack_t **stack, unsigned int counter_line, char *command)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"pint", pint},
		{"swap", swap},
		{"sub", sub},
		{NULL, NULL}};
	int j;

	if (command[0] == '#')
		return;

	for (j = 0; functions[j].opcode != NULL; j++)
	{
		if (strcmp(functions[j].opcode, command) == 0)
		{
			functions[j].f(stack, counter_line);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", counter_line, command);
	free(command);
	freed(stack);
	exit(EXIT_FAILURE);
}
