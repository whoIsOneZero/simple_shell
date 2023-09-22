#include "myshell.h"

/**
 * my_is_chain - check for chain delimiter character. dd.
 * @inform: a pointer to the structure for param and return
 * @buffer: where the command is (char) in buffer. dd.
 * @pos: current position in buffer (address). dd.
 * Return: [is chain delimiter] - 1. [is not] - 0
 */
int my_is_chain(info_t *inform, char *buffer, size_t *pos)
{
	size_t j = *pos;

	if (buffer[j] == '|' && buffer[j + 1] == '|')
	{
		buffer[j] = 0;
		j++;
		inform->cmd_buf_type = CMD_OR;
	}
	else if (buffer[j] == '&' && buffer[j + 1] == '&')
	{
		buffer[j] = 0;
		j++;
		inform->cmd_buf_type = CMD_AND;
	}
	else if (buffer[j] == ';')
	{
		buffer[j] = 0;
		inform->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pos = j;
	return (1);
}

