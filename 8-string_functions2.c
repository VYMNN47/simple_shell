#include "shell.h"

/**
 * is_positive - Check if a string represents a positive integer.
 *
 * @str: The string to check.
 *
 * Return: returns 1 if possible otherwise 0
 */

int is_positive(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}

	return (1);

}

/**
 * _itoa - converts an integer into a string.
 *
 * @n: The integer to convert.
 *
 * Return: returns string.
 */

char *_itoa(int n)
{
	char buff[20];
	int index = 0;

	if (n == 0)
	{
		buff[index++] = '0';
	}

	else
	{
		while (n > 0)
		{
			buff[index++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buff[index] = '\0';

	string_rev(buff, index);

	return (_strdup(buff));
}

/**
* string_rev - reverses the given string.
*
* @string: The string to be reversed.
* @length: length of string.
*/

void string_rev(char *string, int length)
{
	char temp_buff;
	int start = 0, end = length - 1;

	while (start < end)
	{
		temp_buff = string[start];
		string[start] = string[end];
		string[end] = temp_buff;
		start++;
		end--;
	}
}

/**
 * _strtok - tokenizes a string based on delimiters
 *
 * @str: the input string to be tokenized
 * @delim: a string containing the delimiter characters
 *
 * Return: returns pointer to the next token found in string otherwise NULL if
 * no more tokens are found.
 */


char *_strtok(char *str, char *delim)
{
	static char *token;
	char *start;

	if (str != NULL)
	{
		token = str;
	}
	else if (token == NULL || *token == '\0')
	{
		return (NULL);
	}


	while (*token != '\0' && _strchr(delim, *token) != NULL)
	{
		token++;
	}

	if (*token == '\0')
	{
		return (NULL);
	}

	start = token;

	while (*token != '\0' && _strchr(delim, *token) == NULL)
	{
		token++;
	}

	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}

	return (start);
}

/**
* _strchr - function that locates a character in a string
* @s: The string to search.
* @c: The character to locate.
* Return: returns pointer to character if found, otherwise returns NULL
*/

char *_strchr(char *s, char c)
{
	int i = 0;

	if (s == NULL || s[i] == '\0')
	{
		return (NULL);
	}

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}

	return (NULL);
}
