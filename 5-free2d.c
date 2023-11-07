#include "shell.h"

/**
 * free2d - frees a 2d string and NULLs it
 *
 * @str: given string
 *
 * Return: always 0
 */

void free2d(char **str)
{
	int i;

	if (str)
	{
		for (i = 0; str[i]; i++)
		{
			free(str[i]), str[i] = NULL;
		}
		free(str), str = NULL;
	}

	str = NULL;
}
