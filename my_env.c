#include "shell.h"

/**
 * my_env - search environment variable.
 * @argc: arguments.
 *
 * Return: 1 or 0 if failed.
 */
int my_env(void)
{
	int cindy = 0;

	while(environ[cindy])
	{
		write(STDOUT_FILENO, environ[cindy], strlen(environ[cindy]));
		write(STDOUT_FILEOUT, "\n", 1);
		cindy++;
	}
	return (-1);
}

/**
 * my_help -  print man page.
 * @argc: char parameter.
 *
 * Return: 1 or 0 if failed.
 */
int my_help(char **argc)
{
	char *builtin[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	long unsigned int cindy = 0;
	(void)(**argc);

	write(STDOUT_FILENO, "\n---help ---\n", 13);
	write(STDOUT_FILENO, "Type a command \n", 16);
	write(STDOUT_FILENO, "Builtin-in commands:\n", 21);
	for (; cindy < sizeof(builtin) / sizeof(char *); cindy++)
	{
		write(STDOUT_FILENO, "  -> ", 5);
		write(STDOUT_FILENO, builtin[cindy], strlen(builtin[cind]));
		write(STDOUT_FILENO, "\n", 1);
	}
	write(STDOUT_FILENO, "Use the man command for inormation on other programs.\n\n", 57);
	return (-1);
}
