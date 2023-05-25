#include <stdio.h>
#include <stdlib.h>

/**
 * main - edge case.
 *
 * Return: always 0.
 */
int main(void)
{
	char *input = "   \t   \n";
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
