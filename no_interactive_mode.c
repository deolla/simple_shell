#include "shell.h"

/**
 * no_interactive_mode - shell line interpreter
 *
 * Return: no return
 */
void no_interactive_mode(void)
{
	char *input;
	char **argv;
	int condition = -1;

	while (condition == -1)
	{
		input = interpret_stream();
		argv = parse_command(input);
		condition = execute_command(argv);

		free(input);
		free(argv);

		if (condition >= 0)
		{
			exit(condition);
		}
	}
}
