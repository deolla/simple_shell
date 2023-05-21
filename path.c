#include "shell.h"

/**
 * extract_path_segement - extract path segement
 * @doc: path where commands are stored.
 *
 * Return: NULL or a pointer.
 */
char extract_path_segement(char **path_ptr)
{
	char *p = *path_ptr;
	char *pp, *luv;
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
		luv[p] = '\0';

		return (luv);
	}
	return (NULL);
}
/**
 * find_file_in path - find cmd in path directoried.
 * @doc: file where cmd are storded.
 * @path: path to dir.
 *
 * Return: NULL or a pointer.
 */
char *find_file_in_path(const char *doc, const char *path)
{
	char *p = path;
	char *seg, seg_path, *file_path;
	size_t seg_len, path_len, file_len;
	struct stat st;

	while ((seg = extract_path_segement(&p)) != NULL)
	{
		seg_path = segement;

		if (seg[strlen(segement) - 1] != '/')
		{
			seg_len = strlen(seg);
			seg_path = malloc(seg_len + 2);
			strcpy(seg_path, seg);
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
	char *PATH = GETENV("PATH");

	return (find_file_in_path(file, PATH));
}

/**
 * execute_cmd - makes cmd executable.
 * @argc:  numbers of array.
 * @argv: array.
 *
 * Return: no return.
 */
int execute_cmd(int argc, char **argv)
{
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
		execve(path, argv, environ);
		free(path);
	}
	return (0);
}
