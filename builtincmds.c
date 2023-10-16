#include "shell1.h"

/**
 * execute_builtins - Executes a builtin cmd
 * @melody: ...
 * @lin_e: ...
 *
 * Return: 1 if is a built-in cmd
 * or 0 if not
 */
int execute_builtins(char **melody, char *lin_e)
{
	int l = 0;
	char *ls_builtins[] = { "exit", "cd", "help", "env", NULL };

	while (ls_builtins[l])
	{
		if (strincmp(melody[0], ls_builtins[l]) == 0)
		{
			switch (l)
			{
				case 0:
					exit_handle(melody, lin_e);
					break;
				case 1:
					chdir(melody[1]);
					return (1);
				case 2:
					openHelp();
					return (1);
				case 3:
					prnt_environ();
					return (1);
				default:
					break;
			}
		}
		l++;
	}

	return (0);
}
