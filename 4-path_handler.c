#include "shell.h"

/**
 * get_env - Get the value of an environment variable.
 *
 * @variable: The name of the environment variable to retrieve.
 *
 * Return: returns enviroment variable or NULL if not found
 */

char *get_env(char *variable)
{
	char *key, *value, *envi, *temp;
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		temp = _strdup(environ[index]);
		key = _strtok(temp, "=");

		if (_strcmp(key, variable) == 0)
		{
			value = _strtok(NULL, "\n");
			envi = _strdup(value);

			free(temp);

			return (envi);
		}

		free(temp), temp = NULL;
	}

	return (NULL);
}

/**
 * get_path - finds the absolute path of given input command from the PATH
 * variable
 *
 * @cmd: command input by user
 *
 * Return: returns pointer to string with absolute path of command otherwise
 * returns NULL if command isn't found inside of PATH variable
 */

char *get_path(char *cmd)
{
	char *full_cmd, *env_path, *directory;
	int index;
	struct stat path;

	for (index = 0; cmd[index] != '\0'; index++)
	{
		if (cmd[index] == '/')
		{
			if (stat(cmd, &path) == 0)
			{
				return (_strdup(cmd));
			}

			return (NULL);
		}
	}
	env_path = get_env("PATH");
	if (env_path == NULL)
		return (NULL);
	directory = _strtok(env_path, ":");
	while (directory != NULL)
	{
		full_cmd = malloc(2 + _strlen(cmd) + _strlen(directory));
		if (full_cmd != NULL)
		{
			_strcpy(full_cmd, directory);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);

			if (stat(full_cmd, &path) == 0)
			{
				free(env_path);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			directory = _strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
