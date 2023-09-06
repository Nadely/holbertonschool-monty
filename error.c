#include "monty.h"
/**
 * _ferror - error for push function
 *
 * @value: the value for push
 * @counter_line: number of line
 * @stack: header of the stack
 * @new_node: the new node
 *
 * Return: int if success
 */
int _ferror(char *value, unsigned int counter_line, stack_t **stack,
			stack_t *new_node)
{
	int j;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter_line);
		freed(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	for (j = 0; value[j] != '\0'; j++)
	{
		if ((value[j] == 45 || value[j] == 43) && value[j + 1] != '\0')
		{
			continue;
		}
		else if ((value[j] < 48 || value[j] > 57))
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter_line);
			freed(stack);
			free(new_node);
			exit(EXIT_FAILURE);
		}
	}

	return (atoi(value));
}

/**
 * freed - free the stack and value variable
 *
 * @stack: header of stack
 */
void freed(stack_t **stack)
{
	stack_t *tmpstack;

	while (*stack)
	{
		tmpstack = (*stack)->next;
		free(*stack);
		*stack = tmpstack;
	}

	fclose(global.file);
}
