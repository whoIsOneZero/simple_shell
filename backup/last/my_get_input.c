#include "myshell.h"

/**
 * my_get_input - getline of input and remove \n
 * @infos: check header
 * Return: bytes read count
 */

ssize_t my_get_input(info_t *infos)
{
	static char *buf;
	char **buf_p = &(infos->arg), *p;
	static size_t j, i, len;
	ssize_t r = 0;

	my_putchar(BUF_FLUSH);
	r = my_input_buf(infos, &buf, &len);
	if (r == -1) /* ctr+d */
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		my_check_chain(infos, buf, &j, i, len);
		while (j < len)
		{
			if (my_is_chain(infos, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			infos->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (my_strlen(p));
	}

	*buf_p = buf;
	return (r);
}
