#include "myshell.h"
/**
* _strlen - calculates the length of a string
* @s: the string
*
* Return: length of string as int
*/

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (*s++)
		i++;
	return (i);
}
