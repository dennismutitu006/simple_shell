/*by Dennis and Linnet*/
#include "shell.h"

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
size_t _strcspn(const char *str, const char *chars);
char *_strdup(const char *src);

/**
 * _strlen -A functionthat Returns the length of a string.
 * @s: A pointer to the characters string that are passed as arguments.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *s)
{
	int len = 0;

	if (!s)
		return (len);
	for (len = 0; s[len]; len++)
		;
	return (len);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *destTmp;
	const char *src_tmp;

	destTmp = dest;
	src_tmp =  src;

	while (*destTmp != '\0')
		destTmp++;

	while (*src_tmp != '\0')
		*destTmp++ = *src_tmp++;
	*destTmp = '\0';
	return (dest);
}

/**
 * _strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dstlen = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dstlen + i] = src[i];
	dest[dstlen + i] = '\0';

	return (dest);
}

/**
 * _strcspn - Calculates length of number of characters
 * @str: Input string
 * @chars: String containing characters
 *
 * Return: length
 */
size_t _strcspn(const char *str, const char *chars)
{
	size_t len, i;
	int found;

	if (str == NULL || chars == NULL)
		return (0);/*Handle NULL input*/
	len = 0;
	while (str[len] != '\0')
	{
		found = 0;
		for (i = 0; chars[i] != '\0'; i++)
		{
			if (str[len] == chars[i])
			{
				found = 1;
				break;
			}
		}
		if (found)
			break;
		len++;
	}
	return (len);
}

/**
 * _strdup - Duplicates the string
 * @src: String
 *
 * Return: dest
 */
char *_strdup(const char *src)
{
	size_t len;
	char *dest;

	if (src == NULL)
		return (NULL);
	len = _strlen(src) + 1;/*Include the null terminator*/
	dest = (char *)malloc(len);/*Allocate memory*/
	if (dest == NULL)
		return (NULL);/*Memory allocation failed*/
	_strcpy(dest, src);/*Copy the string*/
	return (dest);/*Return the duplicated string*/
}
