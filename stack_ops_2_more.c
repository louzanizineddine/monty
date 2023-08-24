#include "monty.h"

/**
 * stack_mul - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
*/

void stack_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(ms.opcode_tokens, ms.line);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	temp->n *= (*stack)->n;
	/*
		* stack = temp;
		free(temp->next);
		temp->next = NULL;
	*/
	stack_pop(stack, line_number);
}


/**
	* stack_mod - swaps the top two elements of the stack
	* @stack: double pointer to the head of the stack
	* @line_number: line number of the instruction
*/

void stack_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(ms.opcode_tokens, ms.line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(ms.opcode_tokens, ms.line);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	temp->n %= (*stack)->n;
	/*
		* stack = temp;
		free(temp->next);
		temp->next = NULL;
	*/
	stack_pop(stack, line_number);
}
