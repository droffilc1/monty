#include "monty.h"

/**
 * _add -  adds the first two elements of the stack
 * @stack: stack given by main
 * @line: line counter
 *
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line);
	(*stack)->n = res;
}
