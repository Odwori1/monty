#include "monty.h"
/**
 * _pchar -  prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @number: the number
 *
 */
void _pchar(stack_t **stack, unsigned int number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: pointer to lists for stack
 * @number: number of line
 */
void _pstr(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;
	int count = 0;

	(void)number;

	while (temp)
	{
		count = temp->n;
		if (count == 0 || _isalphabet(count) == 0)
			break;
		putchar(count);
		temp = temp->next;
	}
	putchar('\n');
}
