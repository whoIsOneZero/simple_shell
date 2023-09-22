#include "myshell.h"

/**
 * my_strchr - finds char in string
 * @str: the  string
 * @c: the character
 * Return: pointer to the char
 */
char *my_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
