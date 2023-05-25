#include "shell.h"

/**
 * realloc - changes the size of a previously allocated block of memory.
 * @ptr: pointer to old block of memory.
 * @size: new size of block.
 *
 * Return: pointer to new memory block.
 */
void *realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t new_size, old_size;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		new_size = size;
		old_size = sizeof(ptr);
		if (new_size > old_size)
		{
			new_size = old_size;
		}
		my_memcpy(new_ptr, ptr, new_size);

		free(ptr);
	}
	return (new_ptr);
}

/**
 * my_memcpy - copies specific number of bytes.
 * @dest: a pointer to memory location.
 * @src: a pointer to the byte copied.
 * @size: size of bytes to be copied.
 *
 * Return: no return.
 */
void *my_memcpy(void *dest, const void *src, size_t size)
{
	char *dest_ptr = (char *)dest;
	const char *src_ptr = (const char *)src;
	size_t m;

	for (m = 0; m < size; m++)
	{
		dest_ptr[m] = src_ptr[m];
	}
	return (dest);
}
