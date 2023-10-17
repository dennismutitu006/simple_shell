#include "shell.h"

/**
 * _envir - Help information for the builtin env
 * Return: no return
 */
void _envir(void)
{
	char *get = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, get, _strlen(get));

}
/**
 * _setenvir - Help information for the builtin setenv
 * Return: no return
 */
void _setenvir(void)
{

	char *get = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "int replace)\n\t";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, get, _strlen(get));
}
/**
 * _unsetenvir - Help information for the builtin unsetenv
 * Return: no return
 */
void _unsetenvir(void)
{
	char *get = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, get, _strlen(get));
}


/**
 * _generalhelp - Entry point for help information for the help builtin
 * Return: no return
 */
void _generalhelp(void)
{
	char *get = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, get, _strlen(get));
	get = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "unsetenv [variable]\n";
	write(STDOUT_FILENO, get, _strlen(get));
}
/**
 * _exithelp - it help information fot the builint exit
 * Return: no return
 */
void _exithelp(void)
{
	char *get = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, get, _strlen(get));
	get = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, get, _strlen(get));
	get = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, get, _strlen(get));
}
