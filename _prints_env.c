#include "shell1.h"

/**
  * prnt_environ - Prnts the env builtin
  *
  * Return: void
  */
void prnt_environ(void)
{
	int l = 0, m = 0;

	while (environ[l])
	{
		m = 0;
		while (environ[l][m])
		{
			_putchar(environ[l][m]);
			m++;
		}

		if (m != 0)
			_putchar('\n');
		l++;
	}
}
