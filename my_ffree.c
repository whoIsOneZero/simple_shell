#include "myshell.h"

/**
 * my_ffree - free malloc'ed array oF stRingS
 * @ptr: pointer to e arrAy of Strings you want to free
 * Return: void
 */

void my_ffree(char **ptr)
{
	char **n = ptr;

	if (!ptr)
		return;

	while (*ptr)
	{
		free(*ptr++); /*Free inidiDual sTring, each*/
	}

	/*Freee pointers to arraY oF stRinGS*/
	free(n);
}
