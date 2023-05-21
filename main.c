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
	struct new_source source;
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

		source.boff  = input;
		source.boffsize  = strlen(input);
		source.new_post  = SOURCE_INIT_POINT;
		parse_and_execute(&source);

		free(input);

	}

	exit(EXIT_SUCCESS);
}
