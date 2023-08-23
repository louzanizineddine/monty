#ifndef MONTY_H

#define MONTY_H

#define _XOPEN_SOURCE 1000
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct monty_state_s
{
	FILE *f;
	stack_t *stack;
	instruction_t *instructions;
	int value;
	unsigned int current_line;
	int instructions_len;
} monty_state;

void check_file(int argc, char **argv);
void stack_push(stack_t **stack, unsigned int line_number);


void stack_pall(stack_t **stack, unsigned int line_number);
void read_file(char *filename);
char *get_single_line(char *filename, unsigned int line_number);
int get_file_len(char *filename);
char ** tokenize_line(char* line);
void treat_opcode(char *opcode, char* value);
int get_instruction_index(char *opcode);
void trim(char *s);

#endif
