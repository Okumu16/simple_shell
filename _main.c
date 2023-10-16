#include "shell1.h"

/**
  * main - Entry point
  * Return: Always zero.
  */
int main(void)
{
	char *lin_e = NULL, **melody = NULL;
	int w_length = 0, execute_flg = 0;
	size_t lin_e_size = 0;
	ssize_t lin_e_length = 0;

	while (lin_e_length >= 0)
	{
		signal(SIGINT, sig_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		lin_e_length = getline(&lin_e, &lin_e_size, stdin);
		if (lin_e_length == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		w_length = cnt_inpt(lin_e);
		if (lin_e[0] != '\n' && w_length > 0)
		{
			melody = get_toki(lin_e, " \t", w_length);
			execute_flg = execute_builtins(melody, lin_e);
			if (!execute_flg)
			{
				melody[0] = fd_cmd(melody[0]);
				if (melody[0] && access(melody[0], X_OK) == 0)
					exec(melody[0], melody);
				else
					perror("./hsh");
			}

			free_tkns(melody);
		}
	}

	free(lin_e);
	return (0);
}
