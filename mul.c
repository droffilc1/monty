#include "monty.h"

/**
 * _mul -  multiplies the first two elements of the stack
 * @stack: stack given by main
 * @line: line counter
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line);
	(*stack)->n = res;
}
