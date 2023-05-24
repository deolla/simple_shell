#include "shell.h"

/**
 * my_cd - changes working directory
 * @argv: directory
 *
 * Return: 1 or 0 if failed
 */
int my_cd(char **argv)
{
	if(argv[1] == NULL)
	{
		write(STDERR_FILENO, "expected argument to \"cd\"\n", 30);
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("error changing directory: my_cd\n");
		}
	}
	return (-1);
}
