#include "shell.h"

/**
 * _exec - executes the given command
 *
 * @cmd: given command
 * @av: command with arguments
 *
 * Return: returns the exist status of status
 */

int _exec(char **cmd, char **av)
{
	pid_t childpid;
	int status;

	childpid = fork();
	if (childpid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(av[0]);
			free2d(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(childpid, &status, 0);
		free2d(cmd);
	}

	return (WEXITSTATUS(status));
}
