#include "myshell.h"

/**
 * _strdup - duplicate string
 * @str: the string
 * Return: pointer to the resulted string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	for (length++; length--;)
		dup[length] = *--str;

	return (dup);
}
