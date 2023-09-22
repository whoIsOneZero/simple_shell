#include "myshell.h"

/**
 * _strlen - calcs. the length of a string. dd.
 * @str: pointer to the string to calc length. dd.
 * Return: calc'd lenGth of the string. dd.
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

