#include "shell.h"

/**
 * exec_exit - Execute the built-in "exit" command
 * @cmd: An array of command arguments (unused)
 * @status: The exit status of the shell program
 * @av: argument vector
 * @counter: command counmter
 * This function frees allocated memory and exits the shell program with the
 * specified status code.
 */

void exec_exit(char **cmd, char **av, int *status, int counter)
{
	int value = (*status);
	char error_msg[] = ": exit: Illegal number: ";
	char *count;

	if (cmd[1])/*checks if 2nd index of cmd is not NULL*/
	{
		if (is_positive(cmd[1]))/*checks if 2nd index is positive num*/
		{
			value = _atoi(cmd[1]);
		}
		else/*prints error message if otherwise*/
		{
			count = _itoa(counter);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, count, _strlen(count));
			write(STDERR_FILENO, error_msg, _strlen(error_msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(count);
			free2d(cmd);
			(*status) = 2;
			return;
		}
	}

	free2d(cmd);/* Free the allocated memory for command arguments */
	exit(value);/* Terminate the shell program with the given exit status */
}

/**
 * exec_env - Execute the built-in "env" command
 * @cmd: An array of command arguments (unused)
 * @status: The exit status of the shell program (unused)
 *
 * This function prints the environment variables to the standard output.
 */

void exec_env(char **cmd, int *status)
{
	int index;
	(void)status;

	for (index = 0; environ[index] != NULL; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
	}

	free2d(cmd);
	(*status) = 0;
}

/**
 * exec_setenv - executes the builtin command setenv
 * @cmd: given command
 * @status: exit status
 */

void exec_setenv(char **cmd, int *status)
{
	char error_usage[] = "Usage: setenv name value\n";
	char error_prohib[] = "Prohibited usage of (=) in enviroment name\n";
	char error_fail[] = "Setenv failed\n";

	if (cmd[1] == NULL || cmd[2] == NULL)
	{
		write(STDERR_FILENO, error_usage, _strlen(error_usage));
		free2d(cmd);
		return;
	}


	if (_strchr(cmd[1], '=') != NULL)
	{
		write(STDERR_FILENO, error_prohib, _strlen(error_prohib));
		free2d(cmd);
		return;
	}

	if (setenv(cmd[1], cmd[2], 1) != 0)
	{
		write(STDOUT_FILENO, error_fail, _strlen(error_fail));
		free2d(cmd);
		return;
	}

	free2d(cmd);
	(*status) = 0;
}

/**
 * exec_unsetenv - executes the builtin command unsetenv
 * @cmd: given command
 * @status: exit status
 */


void exec_unsetenv(char **cmd, int *status)
{
	char error_usage[] = "Usage: setenv name\n";
	char error_fail[] = "Unsetenv failed\n";

	if (cmd[1] == NULL)
	{
		write(STDERR_FILENO, error_usage, _strlen(error_usage));
		free2d(cmd);
		return;
	}

	if (unsetenv(cmd[1]) != 0)
	{
		write(STDOUT_FILENO, error_fail, _strlen(error_fail));
		free2d(cmd);
		return;
	}
	free2d(cmd);
	(*status) = 0;
}

/**
 * exec_cd - executes the builtin command cd
 * @cmd: given command
 * @av: argument vector
 * @status: exit status
 * @counter: command counter
 */

void exec_cd(char **cmd, char **av, int *status, int counter)
{
	char cdir[PATH_MAX], olddir[PATH_MAX], *home = get_env("HOME");
	char *temp;

	getcwd(olddir, PATH_MAX);
	if (cmd[1] == NULL)
	{
		if (home != NULL)
		{
			chdir(home), setenv("PWD", home, 1);
			setenv("OLDPWD", olddir, 1), free(home), home = NULL;
		}
		free2d(cmd);
		return;
	}
	if (_strcmp(cmd[1], "-") == 0)
	{
		temp = get_env("OLDPWD");
		if (temp == NULL)
		{
			getcwd(cdir, PATH_MAX);
			write(STDOUT_FILENO, cdir, _strlen(cdir));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			chdir(temp), getcwd(cdir, PATH_MAX);
			setenv("OLDPWD", olddir, 1), setenv("PWD", cdir, 1);
			write(STDOUT_FILENO, cdir, _strlen(cdir));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(temp), free(home), free2d(cmd);
		return;
	}
	if (chdir(cmd[1]) != 0)
	{
		printerr(av[0], counter, cmd), free(home), free2d(cmd);
		return;
	}
	getcwd(cdir, PATH_MAX), setenv("OLDPWD", olddir, 1);
	setenv("PWD", cdir, 1), free(home), free2d(cmd), (*status) = 0;
}
