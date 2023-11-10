#include "shell.h"

/**
 * printerr - Print an error message to standard error
 *
 * @name: The name of the shell program or command
 * @count: A count or identifier (e.g., command execution number)
 * @cmd: The command that resulted in an error
 *
 * This function prints an error message in the format:
 * "name: count: cmd: not found\n"
 * to the standard error (STDERR_FILENO).
 */

void printerr(char *name, int count, char **cmd)
{
	char *index, error_msg[] = ": not found\n";
	char cd_msg[] = ": can't cd to ";

	index =  _itoa(count);

	if (_strcmp(cmd[0], "cd") == 0)
	{
		write(STDERR_FILENO, name, _strlen(name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, index, _strlen(index));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
		write(STDERR_FILENO, cd_msg, _strlen(cd_msg));
		write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		write(STDERR_FILENO, name, _strlen(name));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, index, _strlen(index));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
	}

	free(index);
}
