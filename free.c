#include "shell1.h"

/**
  * freeget_environ - ...
  * @environ_pth: The env variable to frees
  *
  * Return: void
  */
void freeget_environ(char *environ_pth)
{
	int i;

	for (i = 4; i >= 0; i--)
		environ_pth--;

	free(environ_pth);
}

/**
  * free_tkns - ......
  * @tokns: ......
  *
  * Return: void
  */
void free_tkns(char **tokns)
{
	char **temp = tokns;

	if (tokns)
	{
		while (*tokns)
			free(*tokns++);

		free(temp);
	}
}
