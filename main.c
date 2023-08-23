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
	
	check_file(argc, argv);

	stack_t *stack = NULL;
	
	instruction_t instructions[] = {
		{"push", stack_push},
		{"pall", stack_pall},
	};

	ms.instructions = instructions;
	ms.stack = &stack;
	ms.instructions_len = 2;

	read_file(argv[1]);
	
	// stack->n = 12;
	// stack->next = NULL;
	// stack->prev = NULL;

	// ms.value = 5;
	// stack_push(&stack, 0);
	// ms.value = 10;
	// stack_push(&stack, 0);
	// ms.value = 50;
	// stack_push(&stack, 0);

	// ms.value = 80;
	// stack_push(&stack, 0);


	// stack_pall(&stack ,0);
	return (0);
}
