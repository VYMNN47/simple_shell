#include "shell.h"

/**
 * _strdup - Duplicates a string.
 *
 * @str: The string to duplicate.
 *
 * Return: returns a pointer to the duplicated string, or NULL if
 * memory allocation fails.
 */

char *_strdup(const char *str)
{
	char *p;
	int index, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*str != '\0')
	{
		len++;
		str++;
	}

	str = str - len;

	p = malloc(sizeof(char) * (len + 1));

	if (p == NULL)
	{
		return (NULL);
	}

	for (index = 0; index <= len; index++)
	{
		p[index] = str[index];
	}

	return (p);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: returns an integer less than, equal to, or greater than 0, if s1 is
 * found to be less than, equal to, or greater than s2, respectively.
 */

int _strcmp(char *s1, char *s2)
{
	int cmpr;

	cmpr = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}

		s1++;
		s2++;
		cmpr = (int)*s1 - (int)*s2;
	}

	return (cmpr);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string.
 *
 * Return: returns the length of the string.
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}

	return (len);
}

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: The destination string.
 * @src: The source string to append to the destination.
 *
 * Return: returns a pointer to the concatenated string.
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = *src;
	return (dest);
}

/**
 * _strcpy - Copies a string from source to destination.
 *
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: returns the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;
	return (dest);
}
