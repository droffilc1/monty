#include "monty.h"

/**
 * rotr -  rotates the stack to the bottom
 * @stack: stack given by main
 * @line: number of lines
 *
 * Return: nothing
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *top, *bottom;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;
	top = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	top->next = NULL;
	(*stack)->prev = bottom;
	(*stack) = bottom;
}
