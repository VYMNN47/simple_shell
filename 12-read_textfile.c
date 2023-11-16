#include "shell.h"

#define BUF_SIZE 1024

/**
 * read_textfile - Read the contents of a file and return them as a string.
 *
 * @av: The array of command-line arguments
 * @counter: counter for commands excuted in the shell
 *
 * Return: A pointer to the string containing the file contents.
 */

char *read_textfile(char **av, int counter)
{
	int f;
	char line[BUF_SIZE];
	ssize_t bytesRead;
	char *count = NULL;
	char err[] = ": Can't open ";

	if (!av[1])
	{
		exit(126);
	}

	f = open(av[1], O_RDONLY);
	if (f == -1)
	{
		if (errno == EACCES)
			exit(126);
		if (errno == ENOENT)
		{
			count = _itoa(counter);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, count, _strlen(count));
			write(STDERR_FILENO, err, _strlen(err));
			write(STDERR_FILENO, av[1], _strlen(av[1]));
			write(STDERR_FILENO, "\n", 1);
			free(count), count = NULL;
			exit(127);
		}
		exit(0);
	}
	bytesRead = read(f, &line[0], BUF_SIZE);
	if (bytesRead == -1 || bytesRead > BUF_SIZE)
		exit(EXIT_FAILURE);
	if (bytesRead == 0)
		exit(0);
	line[bytesRead] = '\0';
	free(count), count = NULL;
	close(f);
	return (strdup(line));
}
