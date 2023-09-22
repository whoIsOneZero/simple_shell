#include "myshell.h"



/**
 * my_alias - man alias
 * @infos: check header,general info
 *  Return: Always 0
 */
int my_alias(info_t *infos)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (infos->argc == 1)
	{
		node = infos->alias;
		while (node)
		{
			my_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; infos->argv[i]; i++)
	{
		p = my_strchr(infos->argv[i], '=');
		if (p)
			my_set_alias(infos, infos->argv[i]);
		else
			my_print_alias(my_node_starts_with(infos->alias, infos->argv[i], '='));
	}

	return (0);
}
