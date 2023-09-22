#include "myshell.h"

/**
 * check_chain - determines whether shell should continue exec. of chain cmd
 * @buff: character containing the comand line (buff). dd.
 * @p: index of the current position (pointer).
 * @inf: information about the previous command (struct). dd.
 * @len: the len of the buff. dd.
 * @h: where the current cmd or chain operation began
 */
void check_chain(info_t *inf, char *buff, size_t *p, size_t h, size_t len)
{
	size_t j = *p;

	if (inf->cmd_buf_type == CMD_AND)
	{
		if (inf->status)
		{
			buff[h] = 0;
			j = len;
		}
	}
	if (inf->cmd_buf_type == CMD_OR)
	{
		if (!inf->status)
		{
			buff[h] = 0;
			j = len;
		}
	}

	*p = j;
}

