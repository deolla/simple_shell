#include "shell.h"

/**
 * realloc - resize a memory block.
 * @pointer: previous allocated memory block.
 * @size: new size in byte.
 *
 * Return: nothing.
 */
void *realloc(void *pointer, size_t size)
{
	void *newpointer;
	size_t oldsize;

	if (size == 0)
	{
		free(pointer);
		return (NULL);
	}

	newpointer = malloc(size);

	if (newpointer == NULL)
	{
		return (NULL);
	}

	if (newpointer != NULL)
	{
		oldsize = size;
		if (size > oldsize)
		{
			oldsize = size;
		}
		memcpy(newpointer, pointer, oldsize);
		free(pointer);
	}
	return (newpointer);
}

/**
 * memcpy - a block of memory from one location to another.
 * @dest: ptr to dest arr.
 * @src: ptr to src.
 * @n: num of bytes.
 *
 * Return: no return.
 */
void *memcpy(void *dest, const void *src, size_t n)
{
	char *dst = dest;
	const char *source = src;
	size_t m;

	for (m = 0; m < n; m++)
	{
		dst[m] = source[m];
	}
	return (dest);
}
