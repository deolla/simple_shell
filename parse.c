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

/**
 * parse_and_execute - parses and executes simple commands from a given source.
 * @source: a pointer to a struct representing the source.
 *
 * Return: 0 if there are no more tokens to process.
 * 1 if the parse and execute process was successful.
 */

int parse_and_execute(struct new_source *source)
{
	struct toks *token;
	struct node *cmdnode;

	ignore_spaces(source);
	token = tokinise(source);

	if (token == &eof_tok)
	{
		return (0);
	}

	while (token && token != &eof_tok)
	{
		cmdnode = parsing_simple_command(token);

		if (!cmdnode)
		{
			break;
		}

		simple_command(cmdnode);
		free_node(cmdnode);
		token = tokinise(source);
	}

	return (1);
}
