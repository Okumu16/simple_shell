#include "shell1.h"

/**
  * strincat - Concatenates two strings with a maximum length
  * @destin: The destinination str
  * @sourc: The source str
  *
  * Return: A pointer to the resulting str destin
  */
char *strincat(char *destin, char *sourc)
{
	int dlength = 0, l = 0;

	while (destin[dlength])
		dlength++;

	for (l = 0; sourc[l] != '\0'; l++)
	{
		destin[dlength] = sourc[l];
		dlength++;
	}

	destin[dlength] = '\0';
	return (destin);
}

/**
  * strinlength - Conts the lengthgth of a str
  * @s: The str to conts
  *
  * Return: The lengthgth of a string
  */
int strinlength(const char *s)
{
	int l = 0;

	while (s[l])
		l++;

	return (l);
}

/**
  * strincmp - Compares two strings the 1st and the 2nd one
  * @strA: The 1st string
  * @strB: The 2nd string
  *
  * Return: integer
  */
int strincmp(char *strA, char *strB)
{
	int length_strA = 0, length_strB = 0, posi = 0, diference = 0, limi = 0;

	length_strA = strinlength(strA);
	length_strB = strinlength(strB);

	if (length_strA <= length_strB)
		limi = length_strA;
	else
		limi = length_strB;

	while (posi <= limi)
	{
		if (strA[posi] == strB[posi])
		{
			posi++;
			continue;
		}
		else
		{
			diference = strA[posi] - strB[posi];
			break;
		}

		posi++;
	}

	return (diference);
}

/**
  * strindup - Dup a str
  * @str: the str to dup
  *
  * Return: the str duplcated
  */
char *strindup(char *str)
{
	int indx = 0, length = 1;
	char *dup_string;

	if (str == NULL)
		return (NULL);

	length = strinlength(str);
	dup_string = malloc((sizeof(char) * length) + 1);
	if (dup_string == NULL)
		return (NULL);

	while (indx < length)
	{
		dup_string[indx] = str[indx];
		indx++;
	}

	dup_string[indx] = '\0';
	return (dup_string);
}

/**
  * str2int - Converts a str to an int.
  * @s: The pntr to convert
  *
  * Return: A int
  */
int str2int(char *s)
{
	int mini = 1, is_int = 0, posi = 0;
	unsigned int blanky = 0;

	while (s[posi])
	{
		if (s[posi] == '-')
			mini *= -1;

		while (s[posi] >= '0' && s[posi] <= '9')
		{
			is_int = 1;
			blanky = (blanky * 10) + (s[posi] - '0');
			posi++;
		}

		if (is_int == 1)
			break;

		posi++;
	}

	blanky *= mini;
	return (blanky);
}
