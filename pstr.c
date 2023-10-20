#include "monty.h"

/**
 * pstr - prints the string  starting at the top of the stack
 * @stack: stack from main
 * @line: number of lines
 *
 * Return: nothing
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
