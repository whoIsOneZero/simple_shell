#include "myshell.h"
/**
 * my_replace_vars - RePlace environment variable refrences in tok cmd.
 * @inf: Pointer to the parameter and return inform struct.
 * Return: [Env var. replaced] -1, [not replaced] - 0
 */
int my_replace_vars(info_t *inf)
{
	int i = 0;
	list_t *node;

	for (i = 0; inf->argv[i]; i++)
	{
		if (inf->argv[i][0] != '$' || !inf->argv[i][1])
			continue;

		if (!my_strcmp(inf->argv[i], "$?"))
		{
			my_replace_string(&(inf->argv[i]),
					my_strdup(my_convert_number(inf->status, 10, 0)));
			continue;
		}
		if (!my_strcmp(inf->argv[i], "$$"))
		{
			my_replace_string(&(inf->argv[i]),
					my_strdup(my_convert_number(getpid(), 10, 0)));
			continue;
		}
		node = my_node_starts_with(inf->env, &inf->argv[i][1], '=');
		if (node)
		{
			my_replace_string(&(inf->argv[i]),
					my_strdup(my_strchr(node->str, '=') + 1));
			continue;
		}
		my_replace_string(&inf->argv[i], my_strdup(""));

	}
	return (0);
}

