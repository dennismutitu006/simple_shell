#include "shell.h"
/**
 * execute_command - Execute a command with arguments
 * @cmd: The command to be executed
 * @args: Arguments for the command
 */
void execute_command(const char *cmd, char *const args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		/* This is the child process*/
		if (execve(cmd, args, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		/* This is the parent process*/
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			fprintf(stderr, "Command failed with status %d\n", WEXITSTATUS(status));
	}
}

