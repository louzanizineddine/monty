#include <stdio.h>
#include <stdlib.h>
#include "monty.h"



/**
 * get_file_len - gets the length of the file
 * @filename: name of the file
 * Return: length of the file
 */

int get_file_len(char *filename)
{
	FILE *file = fopen(filename, "r");
	int lineCount = 0;
	char ch;

	if (file == NULL)
	{
		perror("Error opening file");
		return (-1);
	}


	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
		{
			lineCount++;
		}
	}

	fclose(file);
	return (lineCount);
}


/**
 * get_single_line - gets the line
 * @filename: name of the file
 * @line_number: line number
 * Return: line
 */

char *get_single_line(char *filename, unsigned int line_number)
{

	FILE *file = fopen(filename, "r");
	char *line = (NULL);
	size_t len = 0;
	int read;

	unsigned int current_line = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		current_line++;
		if (current_line == line_number)
		{
			if (line[read - 1] == '\n')
			{
				line[read - 1] = '\0';
			}
			fclose(file);
			return (line);
		}
	}

	fclose(file);
	free(line);
	return (NULL);
}


/**
 * check_file - checks if file is valid
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: pointer to file
 */


void check_file(int argc, char **argv)
{
	FILE *f;

	if ((argc == 1) || (argc > 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");

	if (f == NULL)
	{
		fprintf(stderr, "Error can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ms.f = f;
	fclose(f);
}
