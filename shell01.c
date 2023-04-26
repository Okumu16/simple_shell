#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "main.h"

#define MAX_INPUT_LENGTH 1024

/**
 * read_input - Display prompt and read input from user
 *Return: input
 */
char *read_input()
{
char *input = malloc(MAX_INPUT_LENGTH);
if (input == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

printf("$ ");
fflush(stdout);

if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
{
free(input);
printf("\n");
exit(EXIT_SUCCESS);
}

return (input);
}

/**
 *execute_command - Execute command
 *@command: the argument to be entered
 */
void execute_command(char *command)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
char *argv[] = {command, NULL};
execve(command, argv, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

/**
 *main - Entry point of program
 *Return: 0 always
 */
int main(void)
{
char *input;

while (1)
{
input = read_input();
input[strcspn(input, "\n")] = '\0'; /* Remove trailing newline*/

if (strlen(input) == 0)
{ /*Empty input*/
free(input);
continue;
}

execute_command(input);
free(input);
}

return (0);
}
