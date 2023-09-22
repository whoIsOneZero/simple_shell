#include "myshell.h"

/**
 * my_renumber_history - renumbers history after change
 * @infos: check header
 * Return: count
 */

int my_renumber_history(info_t *infos)
{
	list_t *node = infos->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (infos->histcount = i);
}
