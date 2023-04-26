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

/**
 * get_tokens - get tokens from a command
 * @command: the command
 *
 * Return: tokens
*/
char **get_tokens(const char *command)
{
	size_t token_num, token_pos;
	char *token, **tokens, delimiters[] = {' ', '\n', '\t', '\a'};

	token_num = 64;			/* Let our commands have a maximum of 64 tokens */
	tokens = malloc(token_num * sizeof(char *));
	if (!tokens)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}
}
