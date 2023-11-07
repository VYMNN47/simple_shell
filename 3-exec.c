#include "shell.h"

/**
 * _exec - executes the given command
 *
 * @cmd: given command
 * @av: command with arguments
 *
 * Return: returns the exist status of status
 */

int _exec(char **cmd, char **av, int counter)
{
	pid_t childpid;
	int status; 
	char *full_cmd = NULL;

	full_cmd = get_path(cmd[0]);

	if (full_cmd)
	{
		childpid = fork();
		if (childpid == 0)
		{
			if (execve(full_cmd, cmd, environ) == -1)
			{
				free2d(cmd);
				free(full_cmd), full_cmd = NULL;
			}
		}
		else
		{
			waitpid(childpid, &status, 0);
			free2d(cmd);
			free(full_cmd), full_cmd = NULL;
		}
		return (WEXITSTATUS(status));
	}
	else
	{
		printerr(av[0], counter, cmd[0]);
		free2d(cmd);
		return (127);
	}
}
