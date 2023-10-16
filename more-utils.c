#include "shell1.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
  * _enter - Prints a str
  * @str: The str to prnt
  *
  * Return: void
  */
void _enter(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}

	_putchar('\n');
}

/**
  * strinncmp - Compares at most the 1st n bytes of strA and strB
  * @strA: The 1st str
  * @strB: The 2nd str
  * @length: The limit bytes of compson
  *
  * Return: integer
  */
int strinncmp(const char *strA, const char *strB, size_t length)
{
	unsigned int posi = 0;
	int diference = 0;

	while (posi < length)
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
  * re_alloc - Resize the pointr that was prevly allocated
  * @pointr: pnter prevly allocated
  * @old_sz: old sze of the ptr
  * @new_sz: new sze of the ptr
  *
  * Return: A new ptr to the memory block allocated with the new sze
  */
void *re_alloc(void *pointr, unsigned int old_sz, unsigned int new_sz)
{
	char *npointr;
	unsigned int i;

	if (new_sz == old_sz)
		return (pointr);

	if (pointr == NULL)
	{
		npointr = malloc(new_sz);

		if (npointr == NULL)
			return (NULL);

		return (npointr);
	}
	else
	{
		if (new_sz == 0)
		{
			free(pointr);
			return (NULL);
		}
	}

	npointr = malloc(new_sz);

	if (npointr == NULL)
		return (NULL);

	for (i = 0; i < old_sz && i < new_sz; i++)
	{
		npointr[i] = ((char *) pointr)[i];
	}

	free(pointr);
	return (npointr);
}
