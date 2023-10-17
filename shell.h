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
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/*Declaring an external environment variable*/
extern char **environ;

char *_fgets(char *buf, int size, FILE *stream);
int _printf(const char *format, ...);
/*String functions*/
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *src);
size_t _strcspn(const char *str, const char *chars);

void prompt(void);
void parse_input(char *input, char **cmd, char *args[]);
int parse_command(char *input, char *args[]);
void execute_command(const char *cmd);
void _env(void);
#endif
