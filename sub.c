#include "monty.h"

/**
 * _sub -  subtracts the first two elements of the stack
 * @stack: stack given by main
 * @line: line counter
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line);
	(*stack)->n = res;
}
