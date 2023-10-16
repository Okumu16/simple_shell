#include "shell1.h"

/**
  * cnt_inpt - Counts user's input
  * @str: The str that contains the input
  * Return: The number of words found in the input
  */
int cnt_inpt(char *str)
{
	int l = 0, countword = 0, state = 0;

	while (str[l])
	{
		if (str[l] == ' ' || str[l] == '\n' || str[l] == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			countword++;
		}

		l++;
	}

	return (countword);
}

/**
  * cnt_delim - Counts delimiters the str
  * @str: The str that contains the delim
  * @delim: The delim to will find in the str
  * Return: The num of delims in the str
  */
int cnt_delim(char *str, char *delim)
{
	int l = 0, m = 0, countword = 0;

	while (delim[l])
	{
		m = 0;
		while (str[m])
		{
			if (str[m] == delim[l])
				countword++;
			m++;
		}
		l++;
	}

	return (countword);
}
