#include "myshell.h"

/**
 * my_input_buf - commands to buffer
 * @infos: parameter struct
 * @len: address of len var
 * @buf: address of buffer
 * Return: bytes read
 */


ssize_t my_input_buf(info_t *infos, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, my_sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = my_getline(infos, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] =
					r--;
			}
			infos->linecount_flag = 1;
			my_remove_comments(*buf);
			my_build_history_list(infos, *buf, infos->histcount++);
			{
				*len = r;
				infos->cmd_buf = buf;
			}
		}
	}
	return (r);
}
