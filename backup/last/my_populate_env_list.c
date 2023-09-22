#include "myshell.h"

/**
 * my_populate_env_list - make  env linked list
 * @infos: check header,general info
 * Return: 0
 */
int my_populate_env_list(info_t *infos)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		my_add_node_end(&node, environ[i], 0);

	infos->env = node;

	return (0);
}
