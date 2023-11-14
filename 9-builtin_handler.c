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
	char *builtin_cmds[] = {"exit", "env", "setenv", "unsetenv", "cd",
		"history", NULL};
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

/**
 * exec_builtin - Execute a built-in shell command
 *
 * @cmd: Array of strings representing the command and its arguments
 * @av: Array of strings representing command-line arguments (unused)
 * @status: The exit status of the shell program
 * @counter: Counter to keep track of the number of commands executed (unused)
 *
 * Description: Executes the appropriate built-in command based on cmd[0].
 */
void exec_builtin(char **cmd, char **av, int *status, int counter)
{

	if (_strcmp(cmd[0], "exit") == 0)
	{
		exec_exit(cmd, av, status, counter);
	}

	else if (_strcmp(cmd[0], "env") == 0)
	{
		exec_env(cmd, status);
	}

	else if (_strcmp(cmd[0], "setenv") == 0)
	{
		exec_setenv(cmd, status);
	}

	else if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		exec_unsetenv(cmd, status);
	}

	else if (_strcmp(cmd[0], "cd") == 0)
	{
		exec_cd(cmd, av, status, counter);
	}
}
