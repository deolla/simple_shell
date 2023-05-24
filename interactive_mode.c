#inlcude "shell.h"

/**
 * interactive_mode - shell line interpreter.
 *
 * Return: no return.
 */
void interactive_mode(void)
{
	char *input, **lenght;
	int condition = -1;
	char *prompt = "~$ ";

	while (condition == -1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		input = read_command();
		argc = parse_command(input);
		condition = execute_command(lenght);

		free(input);
		free(lenght);

	}
	if (condition >= 0)
	{
		exit(condition);
	}
}
