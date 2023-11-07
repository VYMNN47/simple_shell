#include "shell.h"

/**
 * tokenizer - takes the input line and tokenizes it
 *
 * @line: input from getline
 *
 * Return: returns the tokenized string
 */

char **tokenizer(char *line)
{
	char *token = NULL;
	char *temp = NULL;
	char **cmd = NULL;
	int tcount = 0, index = 0;

	if (!line)
		return (NULL);
	temp = _strdup(line);
	token = _strtok(temp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}

	while (token != NULL)
	{
		tcount++;
		token = _strtok(NULL, DELIM);
	}
	free(temp), temp = NULL;

	cmd = malloc(sizeof(char *) * (tcount + 1));
	if (cmd == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = _strtok(line, DELIM);
	while (token != NULL)
	{
		cmd[index] = _strdup(token);
		token = _strtok(NULL, DELIM);
		index++;
	}
	free(line), line = NULL;
	cmd[index] = NULL;
	return (cmd);
}
