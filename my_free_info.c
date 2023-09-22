#include "myshell.h"

/**
 * my_free_info - frees info_t
 * @infos:  address
 * @all: if all freed set to true
 */
void my_free_info(info_t *infos, int all)
{
	my_ffree(infos->argv);
	infos->argv = NULL;
	infos->path = NULL;
	if (all)
	{
		if (!infos->cmd_buf)
			free(infos->arg);
		if (infos->env)
			my_free_list(&(infos->env));
		if (infos->history)
			my_free_list(&(infos->history));
		if (infos->alias)
			my_free_list(&(infos->alias));
		my_ffree(infos->environ);
			infos->environ = NULL;
		my_bfree((void **)infos->cmd_buf);
		if (infos->readfd > 2)
			close(infos->readfd);
		my_putchar(BUF_FLUSH);
	}
}
