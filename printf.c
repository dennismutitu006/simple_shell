#include "shell.h"
/**
 * leo_print - our own custom printf.
 * Description: this function will mimic the printf function found in the lib.
 * Return:: no return value on success.
 */
void leo_print(char *string, int descriptor)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}
