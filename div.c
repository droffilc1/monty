#include "monty.h"

/**
 * _div -  subtracts the first two elements of the stack
 * @stack: stack given by main
 * @line: line counter
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line);
	(*stack)->n = res;
}
