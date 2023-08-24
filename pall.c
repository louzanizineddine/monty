#include "monty.h"

/**
	* stack_pall - prints all the values on the stack, starting
	* from the top of the stack.
	* @stack: double pointer to the head of the stack.
	* @line_number: line number of the instruction.
 */

void stack_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return;
	}

	temp = *stack;

	line_number++;
	while (temp != NULL)
	{

		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
