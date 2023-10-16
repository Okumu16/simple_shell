#include "shell1.h"

/**
  * rm_nw_lin - Removes a new lin_e charac 4rm str
  * @string: The string
  *
  * Return: The str without a new lin_e charac
  */
char *rm_nw_lin(char *string)
{
	int l = 0;

	while (string[l])
	{
		if (string[l] == '\n')
			string[l] = '\0';
		l++;
	}

	return (string);
}
