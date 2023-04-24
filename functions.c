#include "main.h"

/**
 * display_prompt - print the prompt string
 * @prompt: the prompt string
*/
void display_prompt(const char *prompt)
{
	printf("%s", prompt);
}

/**
 * get_command - read a line from a file stream
 * @line: the string
 * @stream: file
 * Return: the string, after being written to
*/
char *get_command(char *line, FILE *stream)
{
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stream);
	if (nread < 0)
		if (!feof(stream))
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	return (line);
}
