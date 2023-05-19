#include "shell.h"

/**
 * parsing_simple_command - to parse a simple command using a given token
 * @token: a pointer to a toks containing info about the command
 *
 * Return: NULL indicating an invalid input
 */

struct node *parsing_simple_command(struct toks *token)
{
	struct node *cmdnode;
	struct new_source *source;
	struct node *word;

	if (!token)
	{
		return (NULL);
	}

	cmdnode = new_node(NODE_COMMAND);
	if (!cmdnode)
	{
		free_all_toks(token);
		return (NULL);
	}
	source = token->source;

	do {
		if (token->input[0] == '\n')
		{
			free_all_toks(token);
			break;
		}
		word = new_node(NODE_S);
		if (!word)
		{
			free_node(cmdnode);
			free_all_toks(token);
			return (NULL);
		}
		set_node(word, token->input);
		child_node(cmdnode, word);

		free_all_toks(token);

	} while ((token = tokinise(source)) != &eof_tok);

	return (cmdnode);
}
