#include "shell1.h"

/**
  * concat_path - Concat a path nme and a program nme
  * @pathnme: The path nme to concat with the program nme
  * @prognme: The prog nme to place in the path nme
  *
  * Return: The path nme concat with the program nme
  */
char *concat_path(char *pathnme, char *prognme)
{
	int prog_length = 0, path_length = 0, new_sz = 0;

	prog_length = strinlength(prognme);
	path_length = strinlength(pathnme);
	new_sz = sizeof(char) * (path_length + prog_length + 2);
	pathnme = re_alloc(pathnme, (path_length + 1), new_sz);
	if (!pathnme)
		return (NULL);

	strincat(pathnme, "/");
	strincat(pathnme, prognme);

	return (pathnme);
}

/**
  * fd_cmd - Verify if a cmd is found in the sys
  * @cmd_nme: The cmd nme to fd_cmd in the sys
  *
  * Return: The path nme of the cmd found
  * or NULL if failed
  */
char *fd_cmd(char *cmd_nme)
{
	char *environ_pth = NULL, **hermoso = NULL;
	int i = 0, num_delim = 0;
	struct stat profesor;

	if (cmd_nme)
	{
		if (stat(cmd_nme, &profesor) != 0 && cmd_nme[0] != '/')
		{
			environ_pth = get_env("PATH");
			num_delim = cnt_delim(environ_pth, ":") + 1;
			hermoso = get_toki(environ_pth, ":", num_delim);

			while (hermoso[i])
			{
				hermoso[i] = concat_path(hermoso[i], cmd_nme);

				if (stat(hermoso[i], &profesor) == 0)
				{
					free(cmd_nme);
					cmd_nme = strindup(hermoso[i]);
					freeget_environ(environ_pth);
					free_tkns(hermoso);
					return (cmd_nme);
				}

				i++;
			}

			freeget_environ(environ_pth);
			free_tkns(hermoso);
		}

		if (stat(cmd_nme, &profesor) == 0)
			return (cmd_nme);
	}

	free(cmd_nme);
	return (NULL);
}

/**
  * exec - Executes a cmd
  * @cmd_nme: The cmd to exec
  * @opt_s: The options / flags to the cmd
  *
  * Return: integer
  */
int exec(char *cmd_nme, char **opt_s)
{
	pid_t baby;
	int status;

	switch (baby = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(cmd_nme, opt_s, environ);
		default:
		break;
			do {
				waitpid(baby, &status, WUNTRACED);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
