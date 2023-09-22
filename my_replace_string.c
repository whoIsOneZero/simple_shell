#include "myshell.h"

/**
 * my_replace_string - REplaces an old string with a NeW one. dd.
 * @old: ptr to the string to be repLaced. dd.
 * @nw: The string to replAce the old one with. dd.
 * Return: [Replaced] - 1. [failed] - 0
 */


int my_replace_string(char **old, char *nw)
{
	free(*old);
	*old = nw;


	return (1);
}

