#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

extern int num_arg;

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
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @num_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_variable
{
	FILE *file;
	int num_arg;
	char *buffer;
} global_var;

extern global_var global;

typedef void (*instruct_func)(stack_t **stack, unsigned int number);
instruct_func execute_program(char *str);

void read_input(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int number);

void free_stack(stack_t *head);
int _isalphabet(int c);

void _push(stack_t **stack, unsigned int number);
void _pall(stack_t **stack, unsigned int number);
void _pint(stack_t **stack, unsigned int number);
void _pop(stack_t **stack, unsigned int number);
void _swap(stack_t **stack, unsigned int number);
void _nop(stack_t **stack, unsigned int number);
void _rotl(stack_t **stack, unsigned int number);
void _rotr(stack_t **stack, unsigned int number);

void _pchar(stack_t **stack, unsigned int number);
void _pstr(stack_t **stack, unsigned int number);

void _sub(stack_t **stack, unsigned int number);
void _add(stack_t **stack, unsigned int number);
void _mul(stack_t **stack, unsigned int number);
void _div(stack_t **stack, unsigned int number);
void _mod(stack_t **stack, unsigned int number);

#endif
