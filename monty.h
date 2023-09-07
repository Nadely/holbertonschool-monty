#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_global - structure with the first addres of elements
 * @first: Pointer to stack
 * @buffer: The buffer
 * @file: The file descriptor
 */
typedef struct var_global
{
	stack_t **first;
	char *buffer;
	FILE *file;
} global_t;

global_t global;

int main(int argc, char *argv[]);
void find_file(FILE *file, stack_t **stack);
void execute_cmd(stack_t **stack, unsigned int counter_line, char *command);
int _ferror(char *value, unsigned int counter_line, stack_t **stack,
			stack_t *new_node);
void freed(stack_t **stack);

/* Command functions */
void push(stack_t **stack_file, unsigned int counter_line);
void pall(stack_t **stack_file, unsigned int counter_line);
void pop(stack_t **stack, unsigned int counter_line);
void add(stack_t **stack, unsigned int counter_line);
void nop(stack_t **stack, unsigned int counter_line);
void pint(stack_t **stack, unsigned int counter_line);
void swap(stack_t **stack, unsigned int counter_line);
void sub(stack_t **stack, unsigned int counter_line);
void mul(stack_t **stack, unsigned int counter_line);
void _div(stack_t **stack, unsigned int counter_line);
void mod(stack_t **stack, unsigned int counter_line);
void pchar(stack_t **stack, unsigned int counter_line);
void pstr(stack_t **stack, unsigned int counter_line);

#endif /* MONTY_H */
