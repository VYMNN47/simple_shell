#include "shell.h"

/**
 * get_input - gets the input of the shell
 *
 * Return: returns a pointers to a string of the input, otherwise returns NULL
 */

char *get_input(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t characters;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "SimpleShell$ ", 13);
	}

	characters = getline(&line, &length, stdin);

	if (characters == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
