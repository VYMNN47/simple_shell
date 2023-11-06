#include "shell.h"

/**
 * main - Entry point of the shell.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * Return: 0 on success, or an error code on failure.
 */

int main(int ac, char **av)
{
	char *line = NULL, **cmd = NULL;
	int i, status = 0;
	(void) ac;

	while (1) /*Shell is running until EOF is reached or exit*/
	{
		line = get_input();

		if (line == NULL) /*if EOF is reached or ctrl + D*/
		{
			if (isatty(STDIN_FILENO)) /*checks if associated with terminal or console*/
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}

		cmd = tokenizer(line);

		if (cmd == NULL)
			continue;

		status = _exec(cmd, av);
	}
}
