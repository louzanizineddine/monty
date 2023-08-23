#include "monty.h"

extern monty_state ms;

void read_file(char *filename)
{

	int file_len = 0;
	int temp = 1;
	char *line;
	while(true)
	{
		line = get_line(filename, temp);
		
	}

	printf("file len = %d\n", file_len);


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

void trim(char *s) {
	    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}