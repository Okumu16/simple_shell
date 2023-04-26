#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Simple shell program
 *
 * Return: 0 on success
 */
int main(void)
{
char *buffer;
size_t buffer_size = BUFFER_SIZE;
pid_t pid;
int status;
char *token;
char *path = "/bin/";
char *command;
char *args[2];

buffer = malloc(buffer_size * sizeof(char));
if (buffer == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}

while (1)
{
printf("$ ");
getline(&buffer, &buffer_size, stdin);
token = strtok(buffer, "\n");

if (strcmp(token, "exit") == 0)
{
free(buffer);
exit(0);
}

command = malloc(strlen(path) + strlen(token) + 1);
if (command == NULL)
{
perror("Unable to allocate command buffer");
exit(1);
}
strcpy(command, path);
strcat(command, token);

args[0] = command;
args[1] = NULL;

pid = fork();

if (pid == -1)
{
perror("Unable to fork");
exit(1);
}
else if (pid == 0)
{
/* Child process */
execve(command, args, NULL);
perror("Error executing command");
exit(1);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}

free(command);
}
return (0);
}
