#include "myshell.h"


/**
 * my_unsetenv - delete environment variable
 * @infos: check header,general info
 * @var: env var
 * Return: [ALWAYS] 0.
 */

int my_unsetenv(info_t *infos, char *var)
{
	list_t *node = infos->env;
	char *p;
	size_t i = 0;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = my_starts_with(node->str, var);
		if (p && *p == '=')
		{
			infos->env_changed = my_delete_node_at_index(&(infos->env), i);
			i = 0;
			node = infos->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (infos->env_changed);
}
