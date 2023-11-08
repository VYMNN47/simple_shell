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

void printerr(char *name, int count, char *cmd)
{
	char *index, error_msg[] = ": not found\n";

	index =  _itoa(count);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, error_msg, _strlen(error_msg));

	free(index);
}
