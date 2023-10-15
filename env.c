#include "shell.h"
/**
* env - Implementing shell built-in
* Return: Nothing (void return type)
*/
void _env()
{
        char **env;
        /*Declaring an external environment variable*/
        extern char **environ;

        /*Loop through the environment variables and print them*/
        for (env = environ; *env; env++)
        {
                _printf("%s\n", *env);
        }
}
