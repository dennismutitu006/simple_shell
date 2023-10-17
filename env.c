#include "shell.h"
/**
* env - Implementing shell built-in
* Return: Nothing (void return type)
*/
void _env()
{
	 char **env;
        /*Loop through the environment variables and print them*/
        for (env = environ; *env; env++)
        {
                _printf("%s\n", *env);
        }
}
