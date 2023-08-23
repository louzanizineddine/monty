#include "monty.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


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
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	printf("file name is %s\n", argv[1]);

	f = fopen(argv[1], "r");

	if (f == NULL)
	{
		fprintf(stderr,"Error can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(f);
}

