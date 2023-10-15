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
         // Split the command into its components.
    char *command = strdup(cmd); // Duplicate the input to avoid modifying it.
    char *arg = strtok(command, " ");
    int status;

    // Check if the command is not empty.
    if (arg == NULL) {
        free(command);
        return;
    }

    // Attempt to execute the command.
    if (fork() == 0) {
        // Child process
        execlp(arg, arg, NULL);

        // If execlp returns, the command does not exist.
        printf("Command not found: %s\n", arg);
        exit(1);
    } else {
        // Parent process
        status;
        wait(&status);

        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT) {
            printf("^C\n");
        }
    }

    free(command);
}
