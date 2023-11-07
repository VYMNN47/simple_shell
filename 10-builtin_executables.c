#include "shell.h"

void exec_exit(char **cmd, int status)
{
	free2d(cmd);
	exit(status);
}

void exec_env(char **cmd, int status)
{
	int index;
	(void)status;

	for (index = 0; environ[index] != NULL; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
	}

	free2d(cmd);
}
