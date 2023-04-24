#include "main.h"

/**
 * main - a simple shell program
 * @ac: argument count
 * @av: argument vector
 * Return: 0
*/
int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)))
{
	char *line = NULL;

	do {
		display_prompt("$ ");
		line = get_command(line, stdin);
		printf("%s", line);
	} while (TRUE);

	free(line);
	return (0);
}
