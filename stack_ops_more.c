#include "monty.h"

/**
 * stack_swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the instruction
*/

void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(ms.opcode_tokens, ms.line);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	(*stack)->prev = temp->prev;
	temp->prev = *stack;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

/**
	* stack_add - adds the top two elements of the stack
	* @stack: double pointer to the head of the stack
	* @line_number: line number of the instruction
*/

void stack_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(ms.opcode_tokens, ms.line);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	temp->n += (*stack)->n;
	/*
		* stack = temp;
		free(temp->next);
		temp->next = NULL;
	*/
	stack_pop(stack, line_number);
}


/**
	* stack_nop - doesn't do anything
	* @stack: double pointer to the head of the stack
	* @line_number: line number of the instruction
*/

void stack_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
