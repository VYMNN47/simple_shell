#include "shell.h"

int main(int ac, char **av)
{
	char *line = NULL, **cmd = NULL;
	int status = 0, counter = 0;
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

		counter++;
		cmd = tokenizer(line); /*tokenizes the command string*/

		if (cmd == NULL)
			continue;

		status = _exec(cmd, av, counter); /*executes the give command*/
	}
}
