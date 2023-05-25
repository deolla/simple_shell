#include <stdio.h>
#include <stdlib.h>

/**
 * main - Test case.
 *
 * Return: no return.
 */
int main(void)
{
	char *line = "\n";
	char *input;

	input = read_line();
	printf("Input: %s", input);

	free(input);

	return (0);
}
