#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZE 1024
/**
*main - entry point
*Return: 0 on success
*/
int main(void)
{
char *buffer;
char *argv[2];
size_t bufsize = BUFSIZE;

buffer = (char *)malloc(bufsize * sizeof(char));
if (buffer == NULL)
{
perror("malloc failed");
exit(EXIT_FAILURE);
}
while (1)
{
printf("simple_shell$ ");
getline(&buffer, &bufsize, stdin);
buffer[strcspn(buffer, "\n")] = '\0';

if (strcmp(buffer, "exit") == 0)
{
free(buffer);
exit(EXIT_SUCCESS);
}
if (strcmp(buffer, "env") == 0)
{
system("env");
continue;
}
argv[0] = buffer;
argv[1] = NULL;
if (fork() == 0)
{
execve(argv[0], argv, NULL);
printf("simple_shell: command not found: %s\n", buffer);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
return (0);
}
