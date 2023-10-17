#include "shell.h"
/**
* execute_command -  This function handles PATH
* @command_line: Pointer to char which reads the command passed
* to the command line
*
* Return: Nothing (void return type)
*/
void execute_command(const char *cmd)
{
	char *args[MAX_ARG_LENGTH];
	int arg_count = 0, status;
	char *token, *path, *path_copy, *path_token;
	char full_path[MAX_INPUT_LENGTH];
	pid_t pid;
	
	token = strtok((char *)cmd, " ");
	while (token != NULL && arg_count < MAX_ARG_LENGTH - 1) {
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	if (arg_count == 0) {
		_printf("No command provided.\n");
		return;
	}
	/*Check if the command exists in PATH*/
	path = getenv("PATH");
	path_copy = _strdup(path);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path_token, args[0]);
		if (access(full_path, X_OK) == 0) {
			pid = fork();
			if (pid == -1) {
				perror("fork");
			} else if (pid == 0) {
				/*Child process*/
				execve(full_path, args, NULL);
				perror("execve"); /*execve only returns if there's an error*/
				_exit(EXIT_FAILURE);
			} else {
				/* Parent process*/
				waitpid(pid, &status, 0);
				return;
			}
		}
		path_token = strtok(NULL, ":");
	}
	_printf("Command not found: %s\n", args[0]);
	free(path_copy);
}
