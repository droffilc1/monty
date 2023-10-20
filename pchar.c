#include "monty.h"

/**
* pchar - prints the char at the top of the stack
* @stack: stack from main
* @line: number of lines
*
* Return: nothing
*/
void pchar(stack_t **stack, unsigned int line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n <= 0 || (*stack)->n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
