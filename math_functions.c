#include "monty.h"

/**
 * _sub - sub top of stack by sec top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs
 */
void _sub(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;
	int sub = 0, idx = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		idx++;
	}

	if (stack == NULL || (*stack)->next == NULL || idx <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, number);

	(*stack)->n = sub;
}

/**
 * _div - div top of stack by sec top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int number)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, number);
		(*stack)->n /= div;
	}
}

/**
 * _mul - mul the sec top element of the stack with the top
 * @stack: pointer to lists for monty stack
 * @number: num of line opcode occurs on
 */
void _mul(stack_t **stack, unsigned int number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stack)->n;
		_pop(stack, number);
		(*stack)->n *= aux;
	}
}

/**
 * _mod - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */
void _mod(stack_t **stack, unsigned int number)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		free(global.buffer);
		fclose(global.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		_pop(stack, number);
		(*stack)->n %= mod;
	}
}
