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

/**
 * _rotl - Pass the top to the bottom of the linked list.
 * @stack: Head of the double linked list.
 * @counter_line: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _rotl(stack_t **stack, unsigned int counter_line)
{
	stack_t *tmp1, *tmp2;
	(void)counter_line;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	tmp1 = *stack;
	tmp2 = *stack;

	while (tmp1->next != NULL)
		tmp1 = tmp1->next;

	*stack = tmp2->next;
	(*stack)->prev = tmp2->prev;

	tmp2->next = tmp1->next;
	tmp1->next = tmp2;
	tmp2->prev = tmp1;
}

/**
 * _rotr - Pass the top to the bottom of the linked list.
 * @stack: Head of the double linked list.
 * @counter_line: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _rotr(stack_t **stack, unsigned int counter_line)
{
	stack_t *tmp, *final, *tmp_final;
	(void)counter_line;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	tmp = *stack;
	final = *stack;

	while (final->next != NULL)
		final = final->next;

	tmp_final = final->prev;
	tmp_final->next = final->next;

	final->next = tmp;
	final->prev = tmp->prev;
	tmp->prev = final;

	*stack = final;
}
