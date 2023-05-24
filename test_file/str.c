#include "shell.h"

/**
 * _strlen - determine the length of a null-terminated string.
 * @str: a pointer to the beginning of the string.
 *
 * Return: the number of character in the string.
 */
size_t _strlen(const char *str)
{
	const char *ptr = str;

	while (*ptr != '\0')
	{
		ptr++;
	}
	return (ptr - str);
}

/**
 * _strcmp - compares two null - terminated strings.
 * @str1: first pointer to be compared.
 * @str2: second pointer to be compared.
 *
 * Return: an integer that indicate the result of th caparison.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(const unsigned char *) str - *(const unsigned char *) str2);
}
