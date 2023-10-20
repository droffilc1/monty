#include "monty.h"

/**
 * file_error - prints file error message and exits
 * @argv: argument from main()
 *
 * Description: print error message if not possible to open file
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
/**
 * error_usage - prints usage message and exits
 *
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: pointer to an array of strings
 *
 * Return: nothing
*/
int main(int argc, char **argv)
{
	FILE *file;
	size_t n = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line = 1;
	int status = 0;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while ((getline(&buffer, &n, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line);
		line++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(status);
}
