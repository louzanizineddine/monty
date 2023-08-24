#ifndef MONTY_H

#define MONTY_H

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

/**
	* struct monty_state_s - struct to hold the state of the monty interpreter
	* @f: file pointer
	* @stack: pointer to the top of the stack
	* @instructions: array of instructions
	* @value: value of the instruction
	* @current_line: current line of the file
	* @instructions_len: length of the instructions array
	* @opcode_tokens: tokens of the opcode
	* @line: line
*/

typedef struct monty_state_s
{
	FILE *f;
	stack_t *stack;
	instruction_t *instructions;
	int value;
	unsigned int current_line;
	int instructions_len;
	char **opcode_tokens;
	char *line;
} monty_state;

extern monty_state ms;

void stack_push(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void check_file(int argc, char **argv);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_mul(stack_t **stack, unsigned int line_number);
void stack_mod(stack_t **stack, unsigned int line_number);
void free_all(char **tokens, char *line);
void stack_free(void);
void read_file(char *filename);
char *get_single_line(char *filename, unsigned int line_number);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int get_file_len(char *filename);
char **tokenize_line(char *line);
void treat_opcode(char *opcode, char *value, char **tokens, char *line);
int get_instruction_index(char *opcode);
void trim(char *s);
bool is_digit(char c);
int string_to_int(const char *str, int *error);

#endif
