#include "monty.h"

/**
	* stack_push - pushes an element to the stack.
	* @stack: double pointer to the head of the stack.
	* @line_number: line number of the instruction.
*/

void stack_push(stack_t **stack, unsigned int line_number)
{

	stack_t *new_head, *current_head;

	new_head = (stack_t *)malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		stack_free();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	current_head = *stack;

	line_number++;
	new_head->n = ms.value;
	new_head->next = NULL;
	new_head->prev = current_head;

	if (current_head != NULL)
	{
		current_head->next = new_head;
	}

	*stack = new_head;
}

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


/**
	* stack_pint - prints the value at the top of the stack,
	* followed by a new line.
	* @stack: double pointer to the head of the stack.
	* @line_number: line number of the instruction.
*/

void stack_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	printf("%d\n", temp->n);
}

/**
	* stack_free - frees the stack.
	* Return: void
*/

void stack_free(void)
{
	stack_t *temp;

	while (ms.stack != NULL)
	{
		temp = ms.stack;
		ms.stack = ms.stack->prev;
		free(temp);
	}
}
