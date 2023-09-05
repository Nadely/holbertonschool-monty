#include "monty.h"

/**
 * add - function for adding two stacks
 *
 *@stack: double pointer in begin stack
 *@counter_line: count line in file
 *Return: nothing
 *
 */

void add(stack_t **stack, unsigned int counter_line)
{
	int result = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter_line);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + ((*stack)->next)->n;

	pop(stack, counter_line);
	pop(stack, counter_line);

	push(stack, result);
}
