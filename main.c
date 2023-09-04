#include "monty.h"

int main(int argc, char *argv[])
{
	/*instruction_t command[]= {
		{"push", push},
		{"pall", print_all},
		{"pint", print_int},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nope", nope},
		{NULL, NULL}
	};*/

	ssize_t file, read_file;
	char txt[100];

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1] == NULL)
		exit (EXIT_FAILURE);

	file = open(argv[1], O_RDONLY);

	if (file == -1)
	{
		printf("Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	read_file = read(file, txt, sizeof(argv[1]));

	if (read_file == -1)
		exit(EXIT_FAILURE);
}
