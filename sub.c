#include "monty.h"

/**
 * sub - function for adding two stacks
 *
 *@stack: double pointer in begin stack
 *@counter_line: count line in file
 *Return: nothing
 *
 */

void sub(stack_t **stack, unsigned int counter_line)
{
	int result = 0;
	stack_t *new_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter_line);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n - ((*stack)->next)->n;

	pop(stack, counter_line);
	pop(stack, counter_line);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = result;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

}

