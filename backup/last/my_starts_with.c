#include "myshell.h"

/**
 * my_starts_with - search within 'string' to see if it stats with 'sub'
 * @sub: what to be found
 * @string: where to search in
 * Return: a ptr to the next character of 'string'. dd.
 */
char *my_starts_with(const char *string, const char *sub)
{
	while (*sub)
		if (*sub++ != *string++)
			return (NULL);
	return ((char *)string);
}

