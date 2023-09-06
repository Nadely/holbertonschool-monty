#include "monty.h"
/**
 * push - for push stack
 * @stack: header of stack
 * @counter_line: number of line
 * Return : nothing
 */
void push(stack_t **stack, unsigned int counter_line)
{
	stack_t *new_node;
	char *value;
	int data;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	value = strtok(NULL, " \n\t\r");
	data = _ferror(value, counter_line, stack, new_node);
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

}

/**
 * pall - Print All stack
 * @stack: Addres of first element in stack
 * @counter_line: Number of actual line
 */
void pall(stack_t **stack, unsigned int counter_line)
{
	stack_t *tmp = NULL;

	(void)counter_line;

	if (!stack || !(*stack))
		return;

	tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
