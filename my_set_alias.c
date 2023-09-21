#include "myshell.h"

/**
 * my_set_alias - set alias to a  str
 * @infos: check header,general info
 * @str: string  alias
 *
 * Return:  0, but 1 on error
 */
int my_set_alias(info_t *infos, char *str)
{
	char *p;

	p = my_strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (my_unset_alias(infos, str));

	my_unset_alias(infos, str);
	return (my_add_node_end(&(infos->alias), str, 0) == NULL);
}
