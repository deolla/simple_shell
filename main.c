#include "shell.h"

/**
 * main - defining a function.
 * @argc: argument.
 * @argv: argument.
 *
 * Return: value
 */
int main(int argc, char **argv)
{
	char *input;
	(void)argc;
	(void)argv;

	while (1)
	{
		print_shell_prompt();

		input = read_user_input();

		if (!input)
		{
			exit(EXIT_SUCCESS);
		}

		if (input[0] == '\0' || strcmp(input, "\n") == 0)
		{
			free(input);
			continue;
		}

		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			break;
		}

		write(STDOUT_FILENO, input, strlen(input));
		write(STDOUT_FILENO, "/n", 1);

		free(input);

	}

	exit(EXIT_SUCCESS);
}
