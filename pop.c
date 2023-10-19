#include "monty.h"

/**
* pop - pops the top element
* @stack: stack from main
* @line: line number for error messages
*
* Return: nothing
*/
void pop(stack_t **stack, unsigned int line)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
