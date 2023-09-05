#include "monty.h"

/**
 * pop - out stack
 *@stack: double pointer in begin stack
 *@counter_line: count line in file
 *Return: nothing
 */
void pop(stack_t **stack, unsigned int counter_line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}

