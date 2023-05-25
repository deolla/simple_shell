#include <stdio.h>
#include <stdlib.h>

/**
 * main - Regular test.
 *
 * Return: always 0.
 */
int main(void)
{
	char *line = "Hello, world!\n";
	char *input;

	input = read_line();
	printf("Input: %s", input);

	free(input);

	return (0);
}
