#include "shell.h"

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

/**
 * simple_command - simple shell command.
 * @snode: node.
 *
 * Return: int.
 */
int simple_command(struct node *snode)
{
	struct node *child;
	int argc = 0, result;
	char *argv[MAX_ARGS + 1];

	if (!snode)
		return (0);
	child = snode->first_child;
	if (!child)
		return (0);

	if (!allocate_argument(child, argc, argv))
		return (0);

	result = execute_simple_command(argc, argv);
	free_argv(argc, argv);

	return (result);
}

/**
 * allocate_argument - allocate memory for command arguments.
 * @child: child node.
 * @argc: argument count.
 * @argv: argument array.
 *
 * Return: 1 on success, 0 on failure.
 */
int allocate_argument(struct node *child, int argc, char **argv)
{
	char *str;

	while (child)
	{
		str = child->s.str;
		argv[argc] = malloc(strlen(str) + 1);
		if (!argv[argc])
		{
			free_argv(argc, argv);
			return (0);
		}
		strcpy(argv[argc], str);
		if (++argc >= MAX_ARGS)
			break;
		child = child->next_sib;
	}
	argv[argc] = NULL;
	return (1);
}

/**
 * execute_simple_command - Execute the simple command.
 * @argc: argument count.
 * @argv: argument array.
 *
 * Return: 0 or exit status if failed.
 */
int execute_simple_command(int argc, char **argv)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		implement_command(argc, argv);
		perror("Failed to execute command");
		if (errno == ENOEXEC)
		{
			exit(126);
		}
		else if (errno == ENOENT)
		{
			exit(127);
		}
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		fprintf(stderr, "error: failed to fork command: %s\n", strerror(errno));
		return (0);
	}
	waitpid(child_pid, &status, 0);
	return (1);
}

