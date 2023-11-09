#include "shell.h"

<<<<<<< HEAD
void exec_exit(char **cmd, int *status)
{
	free2d(cmd);
	exit(*status);
}

void exec_env(char **cmd, int *status)
=======
/**
 * exec_exit - Execute the built-in "exit" command
 * @cmd: An array of command arguments (unused)
 * @status: The exit status of the shell program
 *
 * This function frees allocated memory and exits the shell program with the
 * specified status code.
 */

void exec_exit(char **cmd, int status)
{
	free2d(cmd);/* Free the allocated memory for command arguments */
	exit(status);/* Terminate the shell program with the given exit status */
}

/**
 * exec_env - Execute the built-in "env" command
 * @cmd: An array of command arguments (unused)
 * @status: The exit status of the shell program (unused)
 *
 * This function prints the environment variables to the standard output.
 */

void exec_env(char **cmd, int status)
>>>>>>> b34d1def2957df98cde9da3ed229feda0f35dee8
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
