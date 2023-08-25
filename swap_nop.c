#include "monty.h"
/**
 * _swap -  swaps the top two elements of the stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */

void _swap(stack_t **stack, unsigned int number)
{
	stack_t *head;
	int temp;

	head = *stack;
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}

/**
 * _nop - nop doesn’t do anything
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */

void _nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int number)
{
	;
}
