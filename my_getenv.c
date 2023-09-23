#include "myshell.h"

/**
 * my_getenv - returns environ variable
 * @infos: check header,general info
 * @name: environ variable name
 *
 * Return: value requsted
 */
char *my_getenv(info_t *infos, const char *name)
{
	list_t *node = infos->env;
	char *p;

	while (node)
	{
		p = my_starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
