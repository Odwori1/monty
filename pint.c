#include "monty.h"
/**
 * _pint -  prints the value at the top of stack
 * @stack: pointer to the linked list stack
 * @number: number of line
 *
 */
void _pint(stack_t **stack, unsigned int number)
{
	stack_t *h;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
