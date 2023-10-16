#include "shell1.h"

/**
  * get_env - Gets an env var
  * @nme: The var to find in the sys env
  *
  * Return: The content of the env var
  */
char *get_env(const char *nme)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[i])
	{
		if (strinncmp(nme, environ[i], strinlength(nme)) == 0)
		{
			env_var = strindup(environ[i]);
			while (*env_var != '=')
				env_var++;

			++env_var;
			return (env_var);
		}
		i++;
	}

	return (NULL);
}
