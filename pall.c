#include "monty.h"

/**
	* stack_pall - prints all the values on the stack, starting
	* from the top of the stack.
	* @stack: double pointer to the head of the stack.
	* @line_number: line number of the instruction.
 */

void stack_pall(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		printf("stack is empty\n");
		return;
	}

	stack_t *temp = *stack;

	line_number = 9;
	while (temp != NULL)
	{

		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
