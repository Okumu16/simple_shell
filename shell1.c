#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#define MAX_LINE 80
#define MAX_ARGS 10
/**
*read_line - reads the line
*Return: line
*/
char *read_line()
{
char *line = NULL;
size_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
exit(EXIT_SUCCESS);
}
else
{
perror("read_line");
exit(EXIT_FAILURE);
}
}
return (line);
}
/**
*parse_args - Parses the command line arguments and stores them
*@line: the command linestring to be parsed
*Return: args
*/
char **parse_args(char *line)
{
int i = 0;
char **args = malloc(MAX_ARGS * sizeof(char *));
if (args == NULL)
{
perror("parse_args");
exit(EXIT_FAILURE);
}
char *token = strtok(line, " \t\n");
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " \t\n");
}
args[i] = NULL;
return (args);
}
/**
*execute - executes the given command with the
*given arguments and environment variables
*@args: an array of strings that the environment variables
*Return: status
*/
int execute(char **args)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execvp(args[0], args);
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
return (status);
}
}
/**
*main - entry point
*Return: exit_success
*/
int main(void)
{
while (1)
{
printf("$ ");
fflush(stdout);
char *line = read_line();
char **args = parse_args(line);
int status = execute(args);
free(line);
free(args);
}
return (EXIT_SUCCESS);
}
