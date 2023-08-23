#include "monty.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

monty_state ms = {NULL, NULL, NULL, 0, 1, 1};


/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", stack_push},
		{"pall", stack_pall},
	};

	check_file(argc, argv);

	ms.instructions = instructions;
	ms.stack = stack;
	ms.instructions_len = 2;

	read_file(argv[1]);
	return (0);
}
