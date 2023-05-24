#include "shell.h""

/**
 * main - start of a function
 * @argc: numbers of array.
 * @argv: array of strings.
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}
	else
	{
		no_interactive_mode();
	}
	return (0);
}
