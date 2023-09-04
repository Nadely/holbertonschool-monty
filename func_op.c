#include "monty.h"
/**
 * push - for push stack
 * @stack_file: double pointer
 * @number: interger
 * Return : nothing
 */
void push(stack_t ** stack_file, unsigned int number)
{
	stack_t *new_node;

	if (isdigit((int)number) != 0)
	{
		printf("L<line_number>: unknown instruction <opcode>");
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error : malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = *stack_file;

	if (*stack_file != NULL)
		(*stack_file)->prev = new_node;

	*stack_file = new_node;
}
