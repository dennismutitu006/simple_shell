#include "shell.h"
/**
* parse_command - This function parses a command line to args
* @input: contains the command line
* @args: Array of strings where the cmd will be stored
*
* Return: Number of arguments
*/
int parse_command(char *input, char *args[])
{
        char *token;/*Keep track of current token in process*/
        int arg_num = 0;/*Counts no. of args*/

        /*Tokenize the input string using tab and new line*/
        token = strtok(input, " \t\n");

        while (token != NULL)
        {
                /*Copy each arg/token to arguments array*/
                args[arg_num] = _strdup(token);

                /*if we've exceeded the maximum number of arguments*/
                if (arg_num >= MAX_ARG_LENGTH - 1)
                {
                        _printf("Too many arguments\n");
                        return (-1);
                }
                arg_num++;

                /* update the token to the next token in the input*/
                token = strtok(NULL, " \t\n");
        }
        /*Null-terminate the argument array*/
        args[arg_num] = NULL;
	/*Check for the exit command*/
        if (arg_num > 0 && _strcmp(args[0], "exit") == 0) {
            /*Exit the shell.*/
            _printf("Exiting the shell.\n");
            exit(98);
        }
        return (arg_num);
}
