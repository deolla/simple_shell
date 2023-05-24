#include "shell.h"

/**
 * my_env - search environment variable.
 * @argc: arguments.
 *
 * Return: 1 or 0 if failed.
 */
int my_cd(void)
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

