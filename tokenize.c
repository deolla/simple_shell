#include "shell.h"

/**
 * struct toks - end of file.
 * eof_tok - end of file.
 * @description - the end of file token.
 */
struct toks eof_tok = {
	NULL, 0, NULL};

/**
 * include_buff - adds a single character to the token buffer.
 * @k: character variable.
 *
 * Return: no return.
 */
void include_buff(char k)
{
	char *buff_token = NULL, *cont;
	int buff_index_token = -1, buff_size_token = 0;

	if (buff_token == NULL)
	{
		buff_size_token = 1;
		buff_token = malloc(buff_size_token * sizeof(char));
		if (buff_token == NULL)
		{
			perror("Memory allocation failed");
				return;
		}
	}
	buff_token[++buff_index_token] = k;

	if (buff_index_token >= buff_size_token)
	{
		buff_size_token *= 2;
		cont = realloc(buff_token, buff_size_token * 2);

		if (!cont)
		{
			perror("Memory allocated failed");
			return;
		}
		buff_token = cont;
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
	struct toks *token;
	char *next;

	token = malloc(sizeof(struct toks));

	if (!token)
	{
		return (NULL);
	}
	memset(token, 0, sizeof(struct toks));
	token->input_len = strlen(st);

	next = malloc(token->input_len + 1);
	if (!next)
	{
		free(token);
		return (NULL);
	}
	strcpy(next, st);
	token->input = next;

	return (token);
}
/**
 * free_all_toks - frees the memory used by a token structure.
 * @token: tokens.
 *
 * Return: no return.
 */
void free_all_toks(struct toks *token)
{
	if (token->input)
	{
		free(token->input);
	}
	free(token);
}
/**
 * tokinise - tokinise user input.
 * @source: struct variable.
 *
 * Return: end of input
 */
struct toks *tokinise(struct new_source *source)
{
	struct toks *token;
	char *buff_token =  NULL, f;
	int buff_size_token = 0, buff_index_token = -1;

	if (!source || !source->boff || !source->boffsize)
	{
		perror("Error processing source data");
		return (&eof_tok);
	}
	if (!buff_token)
	{
		buff_size_token = 1024;
		buff_token = malloc(buff_size_token);
		if (!buff_token)
		{
			perror("Error allocating token buffer");
			return (&eof_tok);
		}
	}
	buff_index_token    = 0;
	buff_token[0]       = '\0';
	f = my_next_char(source);
	if (f == ERROR_CHARACTER || f == END_OF_FILE)
	{
		return (&eof_tok);
	}
	process_chars(source, f);
	if (buff_index_token == 0)
	{
		return (&eof_tok);
	}
	adjust_buffer_size();
	token = generate_token(buff_token);
	if (!token)
	{
		fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
		return (&eof_tok);
	}
	set_token_source(token, source);
	return (token);
}

/**
 * process_chars - process the character.
 * @source: source.
 * @f: char variable.
 *
 * Return: no return.
 */
void process_chars(struct new_source *source, char f)
{
	int buff_index_token = -1, terminate_loop = 0;

	do {
		switch (f)
		{
			case ' ':
			case '\t':
				if (buff_index_token > 0)
				{
					terminate_loop = 1;
				}
				break;
			case '\n':
				if (buff_index_token > 0)
				{
					get_last_char(source);
				}
				else
				{
					include_buff(f);
				}
				terminate_loop = 1;
				break;
			default:
				include_buff(f);
				break;
		}
		if (terminate_loop)
		{
			break;
		}
	} while ((f = my_next_char(source)) != END_OF_FILE);
}
