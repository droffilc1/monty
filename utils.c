#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: string to be checked
 *
 * Return: 1 (Success). Otherwise 0
 */
int is_digit(char *string)
{
	int i = 0;

	if (string != NULL)
	{
		if (string[i] == '-')
			i++;
		while (string[i])
		{
			if (string[i] < 48 || string[i] > 57)
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}
