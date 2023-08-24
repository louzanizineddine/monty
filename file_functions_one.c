#include "monty.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * read_file - reads the file and executes the instructions
 * @filename: name of the file
 * Return: void
*/

void read_file(char *filename)
{
	int temp = 1;
	char *line;
	char **tokens;

	while (true)
	{
		line = get_single_line(filename, temp);
		if (line == NULL)
			break;
		/*printf("line: %s\n", line);*/
		tokens = tokenize_line(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			free(line);
			temp++;
			continue;
		}

		treat_opcode(tokens[0], tokens[1]);

		free(tokens);
		free(line);
		temp++;
	}

}

/**
 * treat_opcode - treats the opcode
 * @opcode: opcode
 * @value: value
 * Return: void
 */

void treat_opcode(char *opcode, char *value)
{
	int index, error;

	index = get_instruction_index(opcode);
	/*printf("index: %d\n", index);*/
	if (index == -1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ms.current_line, opcode);
		exit(EXIT_FAILURE);
	}

	if (index == 0)
	{
		if (value == NULL || string_to_int(value, &error) == -1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ms.current_line);
			exit(EXIT_FAILURE);
		}
		ms.value = atoi(value);
		ms.instructions[index].f(&(ms.stack), ms.current_line);
	}

	if (index == 1)
	{
		ms.instructions[index].f(&(ms.stack), ms.current_line);
	}
	ms.current_line++;
}

/**
 * get_instruction_index - gets the index of the instruction
 * @opcode: opcode
 * Return: index
 */

int get_instruction_index(char *opcode)
{
	int i;

	for (i = 0 ; i < ms.instructions_len; i++)
	{

		if (strcmp(ms.instructions[i].opcode, opcode) == 0)
		{
			return (i);
		}
	}

	return (-1);
}

/**
 * tokenize_line - tokenizes the line
 * @line: line
 * Return: array of tokens
 */


char **tokenize_line(char *line)
{
	char **arr = (char **)malloc(sizeof(char *) * 2);
	char *token = strtok(line, " \n\t\a\b$");

	if (token == NULL)
	{
		arr[0] = NULL;
		arr[1] = NULL;
		return (arr);
	}

	arr[0] = token;
	token = strtok(NULL, " \n\t\a\b$");

	if (token == NULL)
	{
		arr[1] = NULL;
		return (arr);
	}
	arr[1] = token;
	return (arr);
}


