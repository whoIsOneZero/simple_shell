#include "myshell.h"

/**
 * my_bfree - free Any malloc'ed variable and Nullify teh pointer
 * @p: variable's address to be freed
 * Return: [COULD FREE] - 1; [FREE FAILED] - 0
 */
int my_bfree(void **p)
{
	if (p && *p)
	{
		free(*p); /*Free the memory*/
		*p = NULL; /*To avoid accessing it*/
		return (1);
	}

	return (0);
}
