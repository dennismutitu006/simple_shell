#include "shell.h"
/**
 * main - this is our main source file for the simple shell project.
 * Return: Always 0 on success.
 */
int main(void)
{
	char cmd[250];
	while (1)
	{
		prompt();
		user_input(cmd, sizeof(cmd));
		execute_command(cmd);
	}
	return (0);
}
