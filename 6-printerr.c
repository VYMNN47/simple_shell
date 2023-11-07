#include "shell.h"

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
