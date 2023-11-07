#include "shell.h"

int is_builtin_cmd(char *cmd)
{
	char *builtin_cmds[] = {"exit", "env", "setenv", "cd", "history", NULL};
	int index;

	for (index = 0; builtin_cmds[index] != NULL; index++)
	{
		if (_strcmp(cmd, builtin_cmds[index]) == 0)
		{
			return (1);
		}
	}

	return (0);
}

void exec_builtin(char **cmd, char **av, int status, int counter)
{
	(void)av, (void)counter;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		exec_exit(cmd, status);
	}

	else if (_strcmp(cmd[0], "env") == 0)
	{
		exec_env(cmd, status);
	}
/*
	else if (_strcmp(cmd, "setenv") == 0)
	{
		exec_setenv();
	}

	else if (_strcmp(cmd, "cd") == 0)
	{
		exec_cd();
	}

	else if (_strcmp(cmd, "history") == 0)
	{
		exec_history();
	}*/
}
