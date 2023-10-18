#include "monty.h"

/**
* pall - prints the stack
* @stack: the stack from main
* @line: number of lines
*
* Return: nothing
*/
void pall(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	print_stack(*stack);
}
