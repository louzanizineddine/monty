#include "monty.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	stack_t *stack;
	instruction_t instructions[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"nop", stack_nop},
	};

	stack = NULL;
	ms.f = NULL;

	check_file(argc, argv);

	ms.instructions = instructions;
	ms.stack = stack;
	ms.instructions_len = 4;
	ms.current_line = 0;

	read_file(argv[1]);
	stack_free();
	return (0);
}
