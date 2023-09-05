#include "monty.h"
/**
 * push - for push stack
 * @stack_file: header of stack
 * @counter_line: number of line
 * Return : nothing
 */
void push(stack_t **stack_file, unsigned int counter_line)
{
	stack_t *new_node;
	char *value;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	value = strtok(NULL, " \n\t\r");
	if (atoi(value) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter_line);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(value);
	new_node->prev = NULL;
	if (*stack_file == NULL)
	{
		*stack_file = new_node;
		new_node->next = NULL;
		return;
	}

	printf("check value = %d\n", new_node->n);
	(*stack_file)->prev = new_node;
	new_node->next = *stack_file;
	*stack_file = new_node;
}

/**
 * pall - Print All stack
 * @stack: Addres of first element in stack
 * @counter_line: Number of actual line
 */
void pall(stack_t **stack_file, unsigned int counter_line)
{
	stack_t *tmp = NULL;

	(void)counter_line;

	if (!stack_file || !(*stack_file))
		return;

	tmp = *stack_file;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
