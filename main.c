#include "monty.h"
/**
 * main - execut monty
 *
 * @argc: arguments
 * @argv: pointer char
 *
 * Return: functions
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL, *tmpstack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1] == NULL)
		exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	find_file(file, &stack);

	while (stack)
	{
		tmpstack = stack->next;
		free(stack);
		stack = tmpstack;
	}

	fclose(file);

	return (EXIT_SUCCESS);
}
