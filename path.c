#include "shell.h"
/**
 * find_path - find command in path dir.
 * @doc: file to search.
 * Return: pointer or NULL.
 */
char *find_path(char *doc)
{
	char *PATH = getenv("PATH"), *w = PATH, wa, pway;
	int walp, apen;
	struct stat st;

	while (w && *w)
	{
		wa = w;
		while (*wa && *wa != ':')
			wa++;
		walp = wa - w;
		if (!walp)
			walp = 1;
		apen = strlen(doc);
		pway[wa - w] = '\0';
		if (wa[-1]  != '/')
			strcat(path, "/");
		if (stat(pway, &st) == 0)
		{
			if (!S_ISREG(st.st_mode))
			{
				errno = ENOENT;
				w = wa;
				if (*wa == ':')
					w++;
				continue;
			}
			w = malloc(strlen(pway) + 1);
			if (!w)
				return (NULL);
			strcpy(w, pway);
			return (w);
		}
		else
		{
			w = wa;
			if (*wa == ':')
				w++;
		}
	}
	errno = ENOENT;
	return (NULL);
}

/**
 * implement_command - implement cmd executable.
 * @argc:  numbers of array.
 * @argv: array.
 *
 * Return: 0.
 */
int implement_command(int argc, char **argv)
{
	char *path;
	(void)argc;

	if (strchr(argv[0], '/'))
	{
		execve(argv[0], argv, environ);
	}
	else
	{
		path = find_path(argv[0]);
		if (!path)
		{
			return (0);
		}
		execv(path, argv);
		free(path);
	}
	return (0);
}

/**
 * free_argv - free array.
 * @argc: numbers of array of string.
 * @argv: array of string.
 *
 * Return: no return.
 */
inline void free_argv(int argc, char **argv)
{
	if (!argc)
	{
		return;
	}

	while (argc--)
	{
		free(argv[argc]);
	}
}
