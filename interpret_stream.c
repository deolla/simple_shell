#include "shell.h"

/**
 * interpret_stream - reads stream line.
 *
 * Return: pointer to the read stream.
 */
char *interpret_stream(void)
{
	int cindy = 0, size = 1024, alpha;
	char *input = malloc(sizeof(char) * size);
	/* char *error = "error allocating memory \n"; */
	/* char *err = " error reallocating memory \n"; */

	if (input == NULL)
	{
		fprintf(stderr, "allocation of memory failed");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		alpha = getchar();
		if (alpha == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (alpha == '\n')
		{
			input[cindy] = '\0';
			return (input);
		}
		else
		{
			input[cindy] = alpha;
		}
		cindy++;
		if (cindy >= size)
		{
			size += size;
			input = realloc(input, size);
			if (input == NULL)
			{
				fprintf(stderr, "reallocationof memory failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
