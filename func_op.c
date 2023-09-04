#include "monty.h"
/**
 * push - for push stack
 *
 * Return : nothing
 */
void *push(stack_t ** stack_file, unsigned int number)
{
	(void)stack_file;

	if (isdigit(number) != 0)
	{
		printf("L<line_number>: unknown instruction <opcode>");
		exit(EXIT_FAILURE);
	}

	printf("%d\n", number);
	return(NULL);
}
