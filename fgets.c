#include "shell.h"
/**
* fgets - This is a custom fgets
* @buf: Buffer
* @size: Size
* @stream: specify the file descriptor from
* which to read input
*
* Return: buffer
*/
char *_fgets(char *buf, int size, FILE *stream)
{
	int fd, i;
	char c;
	
	if (size <= 0 || buf == NULL || stream == NULL)
		return (NULL);
	fd = fileno(stream);/*Get the file descriptor from FILE*/
	if (fd == -1)
		return (NULL);/*Unable to get the file descriptor*/
	i = 0;
	while (i < size - 1 && read(fd, &c, 1) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break;
	}
	buf[i] = '\0';
	if (i == 0 && c == '\0')
		return (NULL);/*No characters read, end of file*/
	return (buf);
}
