#include "shell.h"
/**
 * parse_input - This function willl parse input entered by user
 * @input: user input
 * @cmd: command line
 * @args: array of inputs passed to cmd
 *
 * Return: Nothing (void return type)
 */
void parse_input(char *input, char **cmd, char *args[])
{
	char *token = strtok(input, " ");
	int arg_count = 0;
	
	if (token != NULL)
	{
		*cmd = token;
		while ((token = strtok(NULL, " ")) != NULL && arg_count < MAX_ARG_LENGTH - 1)
		{
			args[arg_count] = token;
			arg_count++;
		}
		args[arg_count] = NULL;
	} else {
		*cmd = NULL;
	}
}
