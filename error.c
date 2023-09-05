#include "monty.h"
/**
 * _ferror - error for push function
 *
 * @value: the value for push
 * @counter_line: number of line
 * Return: int if success
 */
int _ferror(char *value, unsigned int counter_line)
{
	int j;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter_line);
		exit(EXIT_FAILURE);
	}

	for (j = 0; value[j] != '\0'; j++)
	{
		if (value[j] != 45 || value[j] != 43)
		{
			continue;
		}
		else if ((value[j] < 48 || value[j] > 57))
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter_line);
			exit(EXIT_FAILURE);
		}
	}

	return (atoi(value));
}
