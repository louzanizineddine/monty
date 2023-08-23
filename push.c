
#include "monty.h"
extern monty_state ms;

/*
	* stack_push - pushes an element to the stack.
	* @stack: double pointer to the head of the stack.
	* @line_number: line number of the instruction.
*/

void stack_push(stack_t **stack, unsigned int line_number)
{
	// if (stack == NULL)
	// {
	// 	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	// 	exit(EXIT_FAILURE);
	// }

	stack_t *new_head = (stack_t *)malloc(sizeof(stack_t));

	if (new_head == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	stack_t *current_head = *stack;

	new_head->n = ms.value;
    new_head->next = NULL;
    new_head->prev = current_head;

    if (current_head != NULL)
    {
        current_head->next = new_head;
    }

    *stack = new_head;
}