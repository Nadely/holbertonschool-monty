#include "monty.h"
/**
 * pchar - print a char with the previous node
 *
 * @stack: header of stack
 * @counter_line: number of line
 */
void pchar(stack_t **stack, unsigned int counter_line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", counter_line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", counter_line);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - print a string
 *
 * @stack: header of stack
 * @counter_line: number of line
 */
void pstr(stack_t **stack, unsigned int counter_line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pstring, stack empty", counter_line);
		exit(EXIT_FAILURE);
	}

	while ((*stack))
	{
		if ((*stack)->n == 0)
			printf("\n");

		if ((*stack)->n < 32 || (*stack)->n > 126)
			exit(EXIT_FAILURE);

		printf("%c", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
