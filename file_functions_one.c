#include "monty.h"

extern monty_state ms;

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
		line = get_line(filename, temp);
		if (line == NULL)
			break;
		printf("original line: %s\n", line);
		tokens = tokenize_line(line);
		printf("%s %s\n", tokens[0], tokens[1]);
		treat_opcode(tokens[0], tokens[1]);
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
	int index;

	index = get_instruction_index(opcode);
	printf("instructino index = %d\n", index);

	if (index == 0)
	{
		ms.value = atoi(value);
	}
	printf("ms.value = %d\n", ms.value);
	ms.instructions[index].f(&(ms.stack), ms.current_line);
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
	char *token = strtok(line, " \t$");

	arr[0] = token;
	token = strtok(NULL, " \t$");

	arr[1] = token;


	return (arr);
}


