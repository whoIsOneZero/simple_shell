#include "myshell.h"

/**
 * my_env - prints current env
 * @infos: check header,general info
 * Return: Always 0
 */
int my_env(info_t *infos)
{
	my_print_list_str(infos->env);
	return (0);
}
