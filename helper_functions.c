#include "monty.h"
/**
 * execute_program -  checks opcode and returns the correct function
 * @str: the opcode
 * Return: returns a functions, or NULL on failure
 */
instruct_func execute_program(char *str)
{
	int idx;

	instruction_t operations[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	idx = 0;
	while (operations[idx].f != NULL && strcmp(operations[idx].opcode, str) != 0)
	{
		idx++;
	}

	return (operations[idx].f);
}

/**
 * read_input - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_input(char *filename, stack_t **stack)
{
	char *line;
	size_t idx = 0;
	int line_count = 1;
	int check;
	int read;
	instruct_func s;

	global.file = fopen(filename, "r");

	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&global.buffer, &idx, global.file)) != -1)
	{
		line = parse_line(global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = execute_program(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(global.buffer);
	check = fclose(global.file);
	if (check == -1)
		exit(-1);
}

/**
 * isnumber - checks if a string is a number
 * @str: string  passed
 * Return: returns 1 if string is a nu or 0
 */
int isnumber(char *str)
{
	int idx = 0;

	if (str == NULL)
		return (0);

	while (str[idx])
	{
		if (str[0] == '-')
		{
			idx++;
			continue;
		}
		if (!isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head
 * @number: the current line num
 * Return: returns the opcode or null
 */
char *parse_line(char *line, stack_t **stack, unsigned int number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			global.num_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}

/**
 * free_stack - free a stack
 * @head: pointer to first node
 *
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
