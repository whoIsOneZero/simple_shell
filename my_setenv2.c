#include "myshell.h"

/**
 * my_setenv - make a new environment variable.
 * @infos: check header,general info
 * @var:  env var
 * @value: env var value
 *  Return: 0
 */

int my_setenv(info_t *infos, char *var, char *value)
{
	char *buf = NULL;
	char *p;
	list_t *node;

	if (!var || !value)
		return (0);

	buf = malloc(my_strlen(var) + my_strlen(value) + 2);
	if (!buf)
		return (1);
	my_strcpy(buf, var);
	my_strcat(buf, "=");
	my_strcat(buf, value);
	node = infos->env;
	while (node)
	{
		p = my_starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			infos->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	my_add_node_end(&(infos->env), buf, 0);
	free(buf);
	infos->env_changed = 1;
	return (0);
}
