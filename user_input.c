#include "shell.h"
/**
 * user_input - receives user input.
 * @cmd: a pointer to where the cmmiand string will be stored.
 * @size: keeps track and updates siz e of the string read.
 * Description: this function will read the userinput and store it in @cmd.
 */
void user_input(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			leo_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	cmd[_strspn(cmd, "\n")] = '\0';
}
