#include "monty.h"

/**
	* is_digit - checks if a character is a digit
	* @c: character to check
	* Return: true if digit, false otherwise
*/

bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
	* string_to_int - converts a string to an integer
	* @str: string to convert
	* @error: pointer to an integer to store error code
	* Return: integer value of string
*/

int string_to_int(const char *str, int *error)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str == NULL || str[0] == '\0')
	{
		*error = 1;
		return (0);
	}

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	} else if (str[0] == '+')
	{
		i = 1;
	}


	while (str[i] != '\0')
	{
		if (!is_digit(str[i]))
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}

	*error = 0;
	return (result * sign);
}


/**
	* free_all - frees all memory
	* @tokens: tokens
	* @line: line
*/

void free_all(char **tokens, char *line)
{
	free(tokens);
	free(line);
	stack_free();
}
