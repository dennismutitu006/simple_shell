#include "shell.h"
/**
 * _printf - This function is a copy of the printf() in stdio.h
 * @format: Lists all types of args passed to the function
 * @...: Variable amount of args that can be passed to the function
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list(var_args);
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(var_args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
			format++;
		} else
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int this_integer = va_arg(var_args, int);
				char this_str[20];

				sprintf(this_str, "%d", this_integer);
				count += write(1, this_str, _strlen(this_str));
			} else if (*format == 'c')
			{
				char c = va_arg(var_args, int);

				write(1, &c, 1);
				count++;
			} else if (*format == 's')
			{
				char *str = va_arg(var_args, char *);

				write(1, str, _strlen(str));
				count++;
			}
			format++;
		}
	}
	va_end(var_args);
	return (count);
}
