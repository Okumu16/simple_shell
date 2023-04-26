#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 512

void execute_command(char *command);
/**
 * main - entry point
 * Return: 0 always
 */
int main(void)
{
char input[MAX_INPUT_LENGTH];
char *command;

while (1)
{
printf("$ ");
if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
{
printf("\n");
exit(EXIT_SUCCESS);
}

command = strtok(input, "\n");
if (command == NULL)
{
continue;
}

execute_command(command);
}

return (EXIT_SUCCESS);
}
/**
 * execute_command - execution of the commands
 *@command: what to be executed
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
if (execlp(command, command, (char *) NULL) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
