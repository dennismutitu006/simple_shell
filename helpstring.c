#include "shell.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *newstr;
	size_t lenght;

	lenght = _strlen(s);
	newstr = malloc(sizeof(char) * (lenght + 1));
	if (newstr == NULL)
		return (NULL);
	_memcpy(newstr, s, lenght + 1);
	return (newstr);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len1;

	for (len1 = 0; s[len1] != 0; len1++)
	{
	}
	return (len1);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *token, *end;
	char *start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		token = str; /*Store first address*/
		i = _strlen(str);
		end = &str[i]; /*Store last address*/
	}
	start = token;
	if (start == end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *token; token++)
	{
		/*Breaking loop finding the next token*/
		if (token != start)
			if (*token && *(token - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*token == delim[i])
			{
				*token = '\0';
				if (token == start)
					start++;
				break;
			}
		}
		if (bool == 0 && *token) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (start);
}

/**
 * _isdigit - it defines if string passed is a number
 *
 * @s: this is the input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
