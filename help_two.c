#include "shell.h"

/**
 * _helper - Help information for the builtin help.
 * Return: no return
 */
void _helper(void)
{
	char *get = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, get, _strlen(get));
}
/**
 * _aliashelp - Help information for the builtin alias.
 * Return: no return
 */
void _aliashelp(void)
{
	char *get = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, get, _strlen(get));
}
/**
 * _cdhelp - it helps information for the builtin alias.
 * Return: no return
 */
void _cdhelp(void)
{
	char *get = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, get, _strlen(get));
}
