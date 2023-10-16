#include "shell1.h"

/**
  * exit_handle - .......
  * @melody: ......
  * @lin_e: ........
  *
  * Return: void
  */
void exit_handle(char **melody, char *lin_e)
{
	int status = 0;

	if (melody[1] == NULL || (!strincmp(melody[1], "0")))
	{
		free_tkns(melody);
		free(lin_e);
		exit(0);
	}
	status = str2int(melody[1]);
	if (status != 0)
	{
		free_tkns(melody);
		free(lin_e);
		exit(status);
	}
	else
	{
		_enter("exit: Illegal number: ");
		_enter(melody[1]);
		_enter("\n");
		exit(2);
	}

	free_tkns(melody);
	free(lin_e);
	exit(EXIT_SUCCESS);
}
