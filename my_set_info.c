#include "myshell.h"

/**
 * my_set_info - makes info_t
 * @info: address
 * @av: argument vector
 */

void my_set_info(info_t *infos, char **av)
{
	int i = 0;

	infos->fname = av[0];
	if (infos->arg)
	{
		infos->argv = my_strtow(infos->arg, " \t");
		if (!infos->argv)
		{
			infos->argv = malloc(sizeof(char *) * 2);
			if (infos->argv)
			{
				infos->argv[0] = my_strdup(infos->arg);
				infos->argv[1] = NULL;
			}
		}
		for (i = 0; infos->argv && infos->argv[i]; i++)
			;
		infos->argc = i;

		my_replace_alias(infos);
		my_replace_vars(infos);
	}
}
