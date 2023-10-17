#include "shell.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int j, up_to;

	up_to = 0;
	for (j = 0; in[j]; j++)
	{
		if (in[j] == '#')
		{
			if (j == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[j - 1] == ' ' || in[j - 1] == '\t' || in[j - 1] == ';')
				up_to = j;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, j, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int l, i_eof;
	char *enter;

	l = 1;
	while (l == 1)
	{
		write(STDIN_FILENO, "$$ ", 4);
		enter = read_line(&i_eof);
		if (i_eof != -1)
		{
			enter = without_comment(enter);
			if (enter == NULL)
				continue;

			if (check_syntax_error(datash, enter) == 1)
			{
				datash->status = 2;
				free(enter);
				continue;
			}
			enter = rep_var(enter, datash);
			l = split_commands(datash, enter);
			datash->counter += 1;
			free(enter);
		}
		else
		{
			l = 0;
			free(enter);
		}
	}
}
/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}
	return (i + 1);
}
/**
 * copy_info - it copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *rec;
	int len_name, len_value, lent;

	len_name = _strlen(name);
	len_value = _strlen(value);
	lent = len_name + len_value + 2;
	rec = malloc(sizeof(char) * (lent));
	_strcpy(rec, name);
	_strcat(rec, "=");
	_strcat(rec, value);
	_strcat(rec, "\0");

	return (rec);
}
