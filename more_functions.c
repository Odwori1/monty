#include "monty.h"
/**
 * _add - add top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @number: number of line opcode occurs on
 */

void _add(stack_t **stack, unsigned int number)
{
	stack_t *temp = *stack;
	int sum = 0, i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, number);

	(*stack)->n = sum;
}

/**
 * _isalphabet - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalphabet(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

/**
 * _rotl -  prints the string starting at the top of the stack
 * @stack: pointer to lists for monty stack
 * @number: number of line
 */
void _rotl(stack_t **stack, unsigned int number)
{
	stack_t *head = *stack;

	int auxiliary = 0;

	if (!number || !stack || !*stack || !(*stack)->next)
		return;

	auxiliary = head->n;

	while (head->next)
	{
		head = head->next;
		head->prev->n = head->n;
	}

	head->n = auxiliary;
}

/**
 * _rotr - rotl rotates the stack to the top
 * @stack: pointer to lists for monty stack
 * @number: number of line
 */
void _rotr(stack_t **stack, unsigned int number)
{
	stack_t *h = *stack;

	int auxiliary = 0;

	if (!number || !stack || !*stack || !(*stack)->next)
		return;

	while (h->next)
		h = h->next;

	auxiliary = h->n;

	while (h->prev)
	{
		h = h->prev;
		h->next->n = h->n;
	}

	h->n = auxiliary;
}
