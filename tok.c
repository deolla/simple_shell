#include "shell.h"

/**
 * adjust_buffer_size - adjust buffer size.
 *
 * Return: no return.
 */
void adjust_buffer_size(void)
{
	int buff_index_token = -1, buff_size_token = 0;
	char *buff_token = NULL;

	if (buff_index_token >= buff_size_token)
	{
		buff_index_token--;
	}
	buff_token[buff_index_token] = '\0';
}

/**
 * set_token_source - set token.
 *
 * @token: token.
 * @source: source.
 * Return: no return.
 */
void set_token_source(struct toks *token, struct new_source *source)
{
	token->source = source;
}
