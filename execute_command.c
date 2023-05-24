#include "shell.h"

/**
 * execute_command - execute user input.
 * @argv: array of string.
 *
 * Return: 1 OR 0 if failed.
 */
int execute_command(char **argv)
{
	unsigned long int cindy = 0;
	char *builtin[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*built_func[])(char **) = {
		&my_cd,
		&my_env,
		&my_help,
		&my_exit
	};

	if (argv[0] == NULL)
	{
		return (-1);
	}

	for (; cindy < sizeof(builtin) / sizeof(char *); cindy++)
	{
		if (strcmp(argv[0], builtin[cindy]) == 0)
		{
			return ((*built_func[cindy])(argv));
		}
	}
	return (updated_process(argv));
}
