#include "monty.h"

/**
 * swap - exchange two stack values
 *
 *@stack: double pointer in begin stack
 *@counter_line: count line in file
 *Return: nothing
 *
 */

void swap(stack_t **stack, unsigned int counter_line)
{
	stack_t *tmp;


	if (*stack == NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter_line);
		exit(EXIT_FAILURE);
	}

	else
	{
		tmp = (*stack)->next;
		(*stack)->prev = tmp;
		(*stack)->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = *stack;
		*stack = tmp;
	}
}
