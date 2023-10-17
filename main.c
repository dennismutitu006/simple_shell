#include "shell.h"
/**
 * main - this is our main source file for the simple shell project.
 * Return: Always 0 on success.
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_length;
	char *args[MAX_ARG_LENGTH];

	while (1)
	{
		prompt();
		input_length = getline(&input, &input_size, stdin);
		if (input_length == -1)
		{
			perror("getline");
			break;
		}
		/*Remove the newline character*/
		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0';
		if (_strcmp(input, "^C") == 0)
			continue;
		if (parse_command(input, args))
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				free(input);
				exit(0);
			} else if (_strcmp(args[0], "_env") == 0)
				_env();
			else
				execute_command(input, args);
		}
	}
	free(input);
	return (0);
}
