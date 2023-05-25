#include "shell.h"

/**
 * my_env - search environment variable.
 * @argv: arguments.
 *
 * Return: 1 or 0 if failed.
 */
int my_env(char **argv)
{
	int cindy = 0;
	(void)(**argv);

	while (environ[cindy])
	{
		write(STDOUT_FILENO, environ[cindy], strlen(environ[cindy]));
		write(STDOUT_FILENO, "\n", 1);
		cindy++;
	}
	return (-1);
}

/**
 * my_help -  print man page.
 * @argv: char parameter.
 *
 * Return: 1 or 0 if failed.
 */
int my_help(char **argv)
{
	unsigned long int cindy = 0;
	char *builtin[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	(void)(argv);

	write(STDOUT_FILENO, "\n---help ---\n", 13);
	write(STDOUT_FILENO, "Type a command \n", 16);
	write(STDOUT_FILENO, "Builtin-in commands:\n", 21);
	for (; cindy < sizeof(builtin) / sizeof(char *); cindy++)
	{
		write(STDOUT_FILENO, "  -> ", 5);
		write(STDOUT_FILENO, builtin[cindy], strlen(builtin[cindy]));
		write(STDOUT_FILENO, "\n", 1);
	}
	write(STDOUT_FILENO, "Use the man command for information.\n\n", 38);
	return (-1);
}
