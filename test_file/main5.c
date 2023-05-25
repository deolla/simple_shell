#include <stdio.h>

/**
 * main - regular test.
 *
 * Return: always 0.
 */
int main(void)
{
	char *input = "ls -l -a\n";
	char **tok;
	int cindy = 0;

	tok = parse_command(input);

	while (tok[cindy] != NULL)
	{
		printf("Token %d: %s\n", cindy, tok[cindy]);
		cindy++;
	}
	free(tok);

	return (0);
}
