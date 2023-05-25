#include <stdio.h>
#include <stdlib.h>

/**
 * main - start of function.
 *
 * Return: no return.
 */
int main(void)
{
	char *input = "ls -l";
	char **argv;
	int condition = -1;

	argv = parse_command(input); /* REGULAR TEST */
	condition = execute_command(argv);

	free(input);
	free(argv);

	return (0);
}
