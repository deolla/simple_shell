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

	if (size == 0)
	{
		free(pointer);
		return (NULL);
	}

	newpointer = malloc(size);

	if (newpointer == NULL)
	{
		retrun (NULL);
	}

	oldsize = pointer ? size_from_header(pointer) : 0;
	copysize = oldsize < size ? oldsize : size;

	memcpy(newpointer, pointer, copysize);

	free(pointer);

	return (newpointer);
}
