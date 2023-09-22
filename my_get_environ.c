#include "myshell.h"

/**
 * get_environ - gets copy of environ
 * @infos: check header
 * Return: pointer to string
 */
char **get_environ(info_t *infos)
{
	if (!infos->environ || infos->env_changed)
	{
		infos->environ = my_list_to_strings(infos->env);
		infos->env_changed = 0;
	}

	return (infos->environ);
}
