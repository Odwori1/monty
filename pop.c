#include "monty.h"
/**
 * _pop - pop an element a list
 *@stack: pointer to first node
 *@number: int
 *Return: void
 */
void _pop(stack_t **stack, unsigned int number)
{
	stack_t *currentNode = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	}
	*stack = currentNode->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(currentNode);
}
