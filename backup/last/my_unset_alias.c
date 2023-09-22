#include "myshell.h"


/**
 * my_unset_alias - makes alias string
 * @infos: check header,general info
 * @str: of alias
 * Return: 0, but 1 if error
 */
int my_unset_alias(info_t *infos, char *str)
{
	char *p, c;
	int ret;

	p = my_strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = my_delete_node_at_index(&(infos->alias),
		my_get_node_index(infos->alias, my_node_starts_with(infos->alias, str, -1)));
	*p = c;
	return (ret);
}
