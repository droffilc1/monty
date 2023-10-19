#include "monty.h"

/**
* opcode - execute builtins
* @stack: stack from main
* @str: string to compare
* @line: number of lines
*
* Return: nothing
*/
void opcode(stack_t **stack, char *str, unsigned int line)
{
	int i = 0;
	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d, unkown instruction %s\n", line, str);
	exit(EXIT_FAILURE);
}
