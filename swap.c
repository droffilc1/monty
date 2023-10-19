#include "monty.h"

/**
 * swap -  swaps top two elements on the stack
 * @stack: stack given by main
 * @line: amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *temp = NULL;
	int n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	n = temp->n;
	temp->n = n;

	temp->n = temp->next->n;
	temp->next->n = n;
}
