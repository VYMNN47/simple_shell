#include "shell.h"

#define BUF_SIZE 1024

/**
 * read_textfile - reads content from text file and returns it to the shell
 * @av: argument vector
 * @counter: counter for commands excuted in the shell
 * Return: returns the read command from file
 */

char *read_textfile(char **av, int counter)
{
	int f;
	char line[BUF_SIZE];
	ssize_t bytesRead;
	char *count = NULL;
	char err[] = ": cannot open ";
	char err2[] = ": No such file\n";

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
			write(STDERR_FILENO, err2, _strlen(err2));
			free(count), count = NULL;
			exit(2);
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