#include "shell.h"

/**
 * parse_command - tokenise input.
 * @input: input to be tokinise.
 *
 * Return: pointer to new array.
 */
char **parse_command(char *input)
{
	int cindy = 0;
	int size = 64;
	char **toks = malloc(size * sizeof(char *));
	char *tok;

	if (!toks)
	{
		write(STDERR_FILENO, "error allocating memory: toks\n", 30);
		exit(EXIT_FAILURE);
	}
	tok = strtok(input, POP_DEL);
	while (tok != NULL)
	{
		if (tok[0] == '#')
		{
			break;
		}
		toks[cindy] = tok;
		cindy++;
		if (cindy >= size)
		{
			size += size;
			toks = realloc(toks, size * sizeof(char *));
			if (!toks)
			{
				write(STDERR_FILENO, "error reallocating memory: toks\n", 32);
			       exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, POP_DEL);
	}
	toks[cindy] = NULL;
	return (toks);
}
