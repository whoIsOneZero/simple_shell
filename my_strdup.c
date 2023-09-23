#include "myshell.h"

/**
 * my_strdup - Create a duplicate of a string
 * @s: string to be duplicaed. dd.
 * Return: the duplicated string (pointer). dd.
 */
char *my_strdup(const char *s)
{
	int len = 0;
	char *dup;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));

	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--s;
	return (dup);
}
