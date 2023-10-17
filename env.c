#include "shell.h"
/**
* _env - Implementing shell built-in
* Return: Nothing (void return type)
*/
void _env(void)
{
	char **env;

	/*Loop through the environment variables and print them*/
	for (env = environ; *env; env++)
	{
		_printf("%s\n", *env);
	}
}
