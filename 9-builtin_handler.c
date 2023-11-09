#include "shell.h"

/**
 * is_builtin_cmd - Check if a command is a built-in shell command
 *
 * @cmd: The command to check
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */

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

<<<<<<< HEAD
void exec_builtin(char **cmd, char **av, int *status, int counter)
=======
/**
 * exec_builtin - Execute a built-in shell command
 *
 * @cmd: Array of strings representing the command and its arguments
 * @av: Array of strings representing command-line arguments (unused)
 * @status: The exit status of the shell program
 * @counter: Counter to keep track of the number of commands executed (unused)
 */

void exec_builtin(char **cmd, char **av, int status, int counter)
>>>>>>> b34d1def2957df98cde9da3ed229feda0f35dee8
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
