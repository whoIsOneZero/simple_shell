#include "myshell.h"

/**
 * my_build_history_list - adds entry for history list
 * @info: check header
 * @linecount: lines cont
 * @buf: buffer
 * Return: 0
 */

int my_build_history_list(info_t *infos, char *buf, int linecount)
{
	list_t *node = NULL;

	if (infos->history)
		node = infos->history;
	my_add_node_end(&node, buf, linecount);

	if (!infos->history)
		infos->history = node;
	return (0);
}
