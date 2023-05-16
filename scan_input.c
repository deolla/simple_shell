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
