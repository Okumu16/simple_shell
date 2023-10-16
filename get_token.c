#include "shell1.h"

/**
  * get_toki - Extract tokie from str
  * @str: The str to get_toki
  * @delim: The delimiter of token
  * @length: tokie number
  *
  * Return: An array of tokie of the string
  */
char **get_toki(char *str, char *delim, int length)
{
	char **tokie = NULL, *token = NULL, *temp = NULL;
	int i = 0;

	tokie = malloc(sizeof(char *) * (length + 1));
	if (!tokie)
		return (NULL);

	str = rm_nw_lin(str);
	temp = strindup(str);
	token = strtok(temp, delim);

	while (token)
	{
		tokie[i] = strindup(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokie[i] = NULL;
	free(temp);
	return (tokie);
}
