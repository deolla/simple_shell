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
		return (str[m] - str2[m]);
	}
}


