#include "monty.h"

extern monty_state ms;

void read_file(char *filename)
{

	int file_len = 0;
	int temp = 1;
	char *line;
	char **tokens;

	while(true)
	{
		line = get_line(filename, temp);
		if (line == NULL) break;
		printf("original line: %s\n", line);
		tokens = tokenize_line(line);
		printf("%s %s\n", tokens[0], tokens[1]);
		treat_opcode(tokens[0], tokens[1]);
		temp ++;
	}

	// printf("file len = %d\n", file_len);
}

void treat_opcode(char *opcode, char* value)
{
	int index;

	index = get_instruction_index(opcode);
	printf("instructino index = %d\n", index);

	if (index == 0) {
		ms.value = atoi(value);
	}
	printf("ms.value = %d\n", ms.value);
	ms.instructions[index].f((ms.stack), ms.current_line);

	// stack_pall(ms.stack, ms.current_line);
	ms.current_line++;
}


int get_instruction_index(char *opcode)
{
	int i;
	for (i = 0 ; i < ms.instructions_len; i++)
	{
		// const char *os = opcode;
		// const char *instruction = ms.instructions[i].opcode;
		if (strcmp(ms.instructions[i].opcode, opcode) == 0)
		{
			return i;
		}
	}
	
}

char ** tokenize_line(char* line) {
	char ** arr = (char *)malloc(sizeof(char *) * 2);

	char *token = strtok(line, " \t$");
	arr[0] = token;

	token = strtok(NULL, " \t$");

	arr[1] = token;


	return arr;
}

int get_file_len(char *filename)
{
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;  // Error code
    }

    int lineCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    fclose(file);
    return lineCount;
}


/**
 * check_file - checks if the file exists and can be opened
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: pointer to the file
 */

char *get_line(char *filename, unsigned int line_number) {

	FILE *file = fopen(filename, "r");
	char *line = (NULL);
	size_t len = 0;
	int read;

	unsigned int current_line = 0;

	while ((read = getline(&line, &len, file)) != -1) {
		current_line++;
		if (current_line == line_number) {
			// Remove the newline character from the end of the line
			if (line[read - 1] == '\n') {
				line[read - 1] = '\0';
			}
			fclose(file);
			return line;
		}
	}

	fclose(file);
	free(line);
	return (NULL);
}