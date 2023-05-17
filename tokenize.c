#include "shell.h"

/**
 * include_buff - adds a single character to the token buffer.
 * @k: character variable.
 *
 * Return: no return.
 */
void include_buff(char k)
{
	int buff_size_token = 0;
	int buff_index_token = -1;
	char *buff_token = NULL;
	char *cont;

	buff_token[buff_index_token++] = k;

	if (buff_index_token >= buff_size_token)
	{
		cont = realloc(buff_token, buff_size_token * 2);

		if (!cont)
		{
			perror("Memory allocated failed");
			return;
		}
		buff_token = cont;
		buff_size_token *= 2;
	}
}
/**
 * generate_token - allocate memory for the token's structure and text.
 * @st: char variable.
 *
 * Return: pointer.
 */
struct toks *generate_token(char *st)
{
	int buff_size_token = 0;
	int buff_index_token = -1;
	char *buff_token = NULL;
	struct toks *tokens;
	char next;

	tokens = malloc(sizeof(struct toks));

	if (!tokens)
	{
		return (NULL);
	}
	memset(tokens, 0, sizeof(struct toks));
	tokens->input_len = strlen(st);

	next = malloc(tokens->input_len + 1);
	if (!next)
	{
		free(tokens);
		return (NULL);
	}
	strcpy(next, st);
	tokens->input = next;

	return (tokens);
}
/**
 * free_all_toks - frees the memory used by a token structure.
 * @tokens: tokens.
 *
 * Return: no return.
 */
void free_all_toks(struct toks *tokens)
{
	int buff_size_token = 0;
	int buff_index_token = -1;
	char *buff_token = NULL;

	if (tokens->input)
	{
		free(tokens->input);
	}
	free(tokens);
}
/**
 * tokinise - tokinise user input.
 * @source: struct variable.
 * Return: end of input
 */
struct toks *tokinise(struct new_source *source)
{
	int buff_size_token = 0, buff_index_token = -1, terminate_loop = 0;
	struct toks *tokens;

	if (!source || !source->boff || !source->boffsize)
		perror("Error processing source data");
		return (&eof_tok);
	if (!buff_token)
	{
		buff_size_token = 1024;
		buff_token = malloc(buff_size_token);
		if (!buff_token)
			perror("Error allocating token buffer");
			return (&eof_tok);
	}

	buff_index_token  = 0;
	buff_token[0]  = '\0';
	f = my_next_char(source);
	if (f == ERROR_CHARCTER || f == END_OF_FILE)
		return (&eof_tok);

	do {
		switch (f)
		{
			case ' ':
			case '\t':
				if (buff_index_token > 0)
					terminate_loop = 1;
				break;
			case '\n':
				if (buff_index_token > 0)
					get_last_char(source);
				else
					include_buff(f);
				terminate_loop = 1;
				break;
			default:
				include_buff(f);
				break;
		} while ((f = my_next_char(source)) != END_OF_FILE)

		if (buff_index_token == 0)
			return (&eof_tok);
		if (buff_index_token > buff_size_token)
			buff_index_token--;
		buff_token[buff_index_token] = '\0';

		tokens = generate_token(buff_token);
		if (!tokens)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
			return (&eof_tok);
		}
		tokens->source = source;
		return (tokens);
}
