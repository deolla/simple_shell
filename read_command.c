#include "shell.h"

/*
 * read_command - read user input
 *
 * Return: a pointer to a str
 */
char *read_command(void)
{
	char *input = NULL;
	size_t size = 0;

	if (getline(&input, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("Error while reading a line");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
