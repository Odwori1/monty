#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @number: number of line opcode occurs on
 */
void _push(stack_t **stack, __attribute__((unused)) unsigned int number)
{
	stack_t *new_node;
	(void)number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = global.num_arg;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int number)
{
	stack_t *head;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
