#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: string to be checked
 *
 * Return: 1 (Success). Otherwise 0
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
