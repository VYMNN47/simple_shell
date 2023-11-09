#include "shell.h"

/**
 * exec_exit - Execute the built-in "exit" command
 * @cmd: An array of command arguments (unused)
 * @status: The exit status of the shell program
 *
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
