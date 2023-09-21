#include "myshell.h"

/**
 * _strncmp - compare two strings to some size only
 * @str1: first string
 * @str2: second string
 * @n: limit of comparison
 * Return: 0 if equal
 */



int _strncmp(const char *str1, const char *str2, size_t n)
{

	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
		{
			return ((int)(unsigned char)str1[i]
				- (int)(unsigned char)str2[i]);
		}
	}
	return (0);
}
