#include "monty.h"
global_t global;

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr,"USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1] == NULL)
		exit (EXIT_FAILURE);

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	find_file(file, &stack);

	return(EXIT_SUCCESS);
}
