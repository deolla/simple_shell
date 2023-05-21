#include "shell.h"

/**
 * new_node - copies the string to allocated memory.
 * @type: argument.
 *
 * Description: copies the string to allocated memory.
 * Return: no return.
 */
struct node *new_node(enum node_type type)
{
	struct node *snode = malloc(sizeof(struct node));

	if (!snode)
	{
		return (NULL);
	}

	memset(snode, 0, sizeof(struct node));
	snode->type = type;

	return (snode);
}

/**
 * child_node - adds a new child node.
 * @parent: parent node.
 * @child: child node.
 *
 * Return: no return.
 */
void child_node(struct node *parent, struct node *child)
{
	struct node *sib;

	if (!parent || !child)
	{
		return;
	}

	if (!parent->first_child)
	{
		parent->first_child = child;
	}
	else
	{
		sib = parent->first_child;

		while (sib->next_sib)
		{
			sib = sib->next_sib;
		}
		sib->next_sib = child;
		child->prev_sib = sib;
	}
	parent->children++;
}

/**
 * set_node - set node's value to given string.
 * @snode: node.
 * @s: variable.
 *
 * Return: no return.
 */
void set_node(struct node *snode, char *s)
{
	char *s1;

	snode->s_type = S_STR;

	if (!s)
	{
		snode->s.str = NULL;
	}
	else
	{
		s1 = malloc(strlen(s) + 1);
		if (!s1)
		{
			snode->s.str = NULL;
		}
		else
		{
			strcpy(s1, s);
			snode->s.str = s1;
		}
	}
}

/**
 * free_node - free nodes.
 * @snode: node to be freed.
 *
 * Return: no return.
 */
void free_node(struct node *snode)
{
	struct node *child;
	struct node *next;

	if (!snode)
	{
		return;
	}

	child = snode->first_child;
	while (child)
	{
		next = child->next_sib;
		free_node(child);
		child = next;
	}

	if (snode->s_type == S_STR)
	{
		if (snode->s.str)
		{
			free(snode->s.str);
		}
	}
	free(snode);
}

/**
 * free_argv - free array.
 * @argc: numbers of array of string.
 * @argv: array of string.
 *
 * Return: no return.
 */
static inline void free_argv(int argc, char **argv)
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
 * return: 0 or 1 if failed.
 */
int simple_command(struct node *snode)
{
	struct node *child;
	int argc, status = 0; 
	long max_args = 255;
	char *argv[max_args + 1], *str;

	if (!snode)
	{
		return (0);
	}
	child = snode->first_child;
	if(!child)
	{
		return (0);
	}
	while (child)
	{
		str = child->s.str;
		argv[argc] = malloc(strlen(str) + 1);
		if (!argc[argc])
		{
			free_argv(argc, argv);
			return 0;
		}
		strcpy(argv[argc], str);
		if(++argc >= max_args)
		{
			break;
		}
		child = child->next_sib;
	}
	argv[argc] = NULL;
	child_pid = 0;
	if ((child_pid = fork()) = 0)
	{
		execute_command(argc, argv);
		perror();
		if (errno == ENOEXEC)
		{
			EXIT(126);
		}
		else if (errno == ENOENT)
		{
			EXIT(127);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid < 0)
	{
		fprintf(stderr, "error: failed to fork command: %s\n", strerror(errno));
		return (0);
	}
	waitpid(child_pid, &status, 0);
	free_argv(argc, argv);

	return (1);
}
