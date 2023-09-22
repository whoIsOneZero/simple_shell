#include "myshell.h"


/**
 * my_is_delim - if character delimeter
 * @chr: charachter
 * @delim: the delimeter
 * Return: 1 if it is delimeteer, otherwise 0
 */
int my_is_delim(char chr, char *delim)
{
	while (*delim)
		if (*delim++ == chr)
			return (1);
	return (0);
}
