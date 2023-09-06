#include "monty.h"

/**
 * pint - print previous elemnet
 *
 *@stack: double pointer in begin stack
 *@counter_line: count line in file
 *Return: nothing
 *
 */

void pint(stack_t **stack, unsigned int counter_line)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter_line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
