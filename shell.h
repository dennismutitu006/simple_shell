#ifndef SHELL_H
#define SHELL_H
#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_LENGTH 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
void prompt();
void user_input(char *cmd, size_t size);
void execute_command(const char *cmd);
void leo_print(char *string, int descriptor);
#endif
