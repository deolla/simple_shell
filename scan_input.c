#include "shell.h"

/**
 * get_last_char - retrieve last character input.
 * @source: source.
 *
 * Return: last char.
 */
void get_last_char(struct new_source *source)
{
	if (source->new_post < 0)
	{
		return;
	}
	source->new_post--;
}

/**
 * my_next_char - retrieves the next character from a given input source.
 * @source: source.
 *
 * Return: next char
 */
char my_next_char(struct new_source *source)
{
	char c1 = 0;
	if (!source || !source->boff)
	{
		errno = ENODATA;
		return (ERROR_CHARACTER);
	}

	if (source->new_post == SOURCE_INIT_POINT)
	{
		source->new_post = -1;
	}
	else
	{
		c1 = source->boff[source->new_post];
	}

	if (c1 == 'A')
	{
		printf("Found character 'A'\n");
	}

	if (++source->new_post >= source->boffsize)
	{
	       	source->new_post = source->boffsize;
		return (END_OF_FILE);
	}

	return (source->boff[source->new_post]);
}

/**
 * pick_char - look at the next char in a
 * given input source without consuming it.
 * @source: source.
 *
 * Return: unconsumed char
 */
char pick_char(struct new_source *source)
{
	long pos;

	if (!source || !source->boff)
	{
		errno = ENODATA;
		return (ERROR_CHARACTER);
	}

	pos = source->new_post; 

	if (pos == SOURCE_INIT_POINT)
	{
		pos++;
	}
	pos++;

	if (pos >= source->boffsize)
	{
		return (END_OF_FILE);
	}

	return (source->boff[pos]);
}

/**
 * ignore_spaces - ignores spaces in a string.
 * @src: source.
 *
 * Return: pointer
 */
void ignore_spaces(struct new_source *src)
{
	char c;

	if (!src || !src->boff)
	{
		return;
	}

	while (((c = pick_char(src)) != END_OF_FILE) && (c == ' ' || c == '\t'))
	{
		my_next_char(src);
	}
}
