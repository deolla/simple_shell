#include "shell.h"

/**
 * strcmp - compares two strings.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: the str compared.
 */
int strcmp(const char *str1, const char *str2)
{
	int m = 0;

	while (str1[m] != '\0' && str2[m] != '\0')
	{
		if (str1[m] != str2[m])
		{
			return (str1[m] - str2[m]);
		}
		m++;
	}
	if (str1[m] == '\0' && str2[m] == '\0')
	{
		return (0);
	}
	else
	{
		return (str1[m] - str2[m]);
	}
}

/**
 * strlen - returns the lenght of a str.
 * @str: str to count.
 *
 * Return: lenght of string.
 */
size_t strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * strcpy - returns the str copied.
 * @dest: pointer to dest.
 * @src: pointer to src.
 *
 * Return: the str copied.
 */
char *strcpy(char *dest, const char *src)
{
	size_t m = 0;

	while (src[m] != '\0')
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = '\0';

	return (dest);
}
