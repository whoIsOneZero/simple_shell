#include "myshell.h"

/**
 * my_replace_alias - ReplAces command aliases in e tokenized cmd line
 * @inf: A ptr to e parameter & return inf struct. dd.
 * Return: [alias replaced] - 1, [not replaced] - 0
 */
int my_replace_alias(info_t *inf)
{
	int n;
	list_t *node;
	char *ptr;

	for (n = 0; n < 10; n++)
	{
		node = my_node_starts_with(inf->alias, inf->argv[0], '=');
		if (!node)
			return (0);
		free(inf->argv[0]);
		ptr = my_strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = my_strdup(ptr + 1);
		if (!ptr)
			return (0);
		inf->argv[0] = ptr;
	}
	return (1);
}

