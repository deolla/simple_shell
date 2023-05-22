#include "shell.h"

/**
 * extract_path_segement - extract path segement
 * @path_ptr: path where commands are stored.
 *
 * Return: NULL or a pointer.
 */
char *extract_path_segement(const char **path_ptr)
{
	const char *p = *path_ptr;
	const char *pp;
	char *luv;
	int bug;

	while (p && *p)
	{
		pp = p;

		while (*pp && *pp != ':')
		{
			pp++;
		}

		bug = pp - p;
		if (!bug)
		{
			bug = 1;
		}

		*path_ptr = pp;
		if (*pp == ':')
		{
			(*path_ptr)++;
		}
		luv = malloc(bug + 1);
		strncpy(luv, p, bug);
		luv[bug] = '\0';

		return (luv);
	}
	return (NULL);
}
/**
 * find_file_in_path - find cmd in path directoried.
 * @doc: file where cmd are storded.
 * @path: path to dir.
 *
 * Return: NULL or a pointer.
 */
char *find_file_in_path(const char *doc, const char *path)
{
	const char *p = path;
	char *segement, *seg_path, *file_path;
	size_t seg_len, path_len, file_len;
	struct stat st;

	while ((segement = extract_path_segement(&p)) != NULL)
	{
		seg_path = segement;

		if (segement[strlen(segement) - 1] != '/')
		{
			seg_len = strlen(segement);
			seg_path = malloc(seg_len + 2);
			strcpy(seg_path, segement);
			seg_path[seg_len] = '/';
			seg_path[seg_len + 1] = '\0';
		}

		path_len = strlen(seg_path);
		file_len = strlen(doc);
		file_path = malloc(path_len + file_len + 1);
		strcpy(file_path, seg_path);
		strcat(file_path, doc);

		if (stat(file_path, &st) == 0)
		{
			if (!S_ISREG(st.st_mode))
			{
				errno = ENOENT;
				continue;
			}

			return (file_path);
		}
		free(file_path);
	}
	errno = ENOENT;
	return (NULL);
}

/**
 * find_path - search cmd in PATH dir.
 * @doc: cmd is stored.
 *
 * Return: pointer.
 */
char *find_path(char *doc)
{
	char *PATH = getenv("PATH");

	return (find_file_in_path(doc, PATH));
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
