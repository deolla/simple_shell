#include "shell.h"
/**
 * read_user_input - reads user input.
 * Return: pointer.
 */
char *read_user_input(void)
{
	char buff[1024];
	char *point = NULL, *point1, pointlen = 0;
	int bufflen;

	while (fgets(buff, 1024, stdin))
	{
		bufflen = strlen(buff);
		if (!point)
		{
			point = malloc(bufflen + 1);
		}
		else
		{
			point1 = realloc(point, pointlen + bufflen + 1);
			if (point1)
			{
				point = point1;
			}
			else
			{
				free(point);
				point = NULL;
			}
		}
		if (!point)
		{
			perror("error: failed to alloc buffer");
			return (NULL);
		}
		strcpy(point + pointlen, buff);
		if (buff[bufflen - 1] == '\n')
		{
			if (bufflen == 1 || buff[bufflen - 2] != '\\')
				return (point);

			point[pointlen + bufflen -2] = '\0';
			bufflen -= 2;
			print_shell_prompt1();
		}
		pointlen += bufflen;
	}
	return (point);
}
