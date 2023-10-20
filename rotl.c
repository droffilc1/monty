#include "monty.h"

/**
 * rotl -  rotates the stack to the top
 * @stack: stack given by main
 * @line: number of lines
 *
 * Return: nothing
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *left, *right;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	/* set left, right with the same value */
	left = right = *stack;

	/* traverse the list */
	while (right->next)
		/* assign right to the next value */
		right = right->next;

	/* assign the next element to the prev element */
	right->next = left;
	/* assign the prev element to the next */
	left->prev = right;
	/* set the top element forming a circular list */
	*stack = left->next;
	/* set the next pointer */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
