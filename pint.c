#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: stack from main
 * @line: number of lines
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
