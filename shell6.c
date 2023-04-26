#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _strlen - compute length of a string
 * @s: the string to measure
 *
 * Return: length of string
 */
size_t _strlen(const char *s)
{
size_t len = 0;

while (s[len])
len++;

return (len);
}

/**
 * _puts - write a string to standard output
 * @str: the string to write
 */
void _puts(char *str)
{
size_t len = _strlen(str);

write(STDOUT_FILENO, str, len);
}

/**
 * main - entry point for shell program
 *
 * Return: 0 on success
 */
int main(void)
{
char buffer[BUFFER_SIZE];
ssize_t bytes_read;
int i;

while (1)
{
_puts("$ ");
bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytes_read == -1)
{
perror("read");
exit(EXIT_FAILURE);
}
if (bytes_read == 0)
break;
for (i = 0; i < bytes_read; i++)
{
if (buffer[i] == '\n')
{
buffer[i] = '\0';
break;
}
}
printf("You typed: %s\n", buffer);
}

return (0);
}
