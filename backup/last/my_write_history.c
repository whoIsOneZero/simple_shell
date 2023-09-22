#include "myshell.h"

/**
 * my_write_history - writes or append to history file
 * @infos:  check header file
 *
 * Return: 1 , and -1 if fails
 */

int my_write_history(info_t *infos)
{
	list_t *node = NULL;
	ssize_t fd;
	char *filename = my_get_history_file(infos);

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = infos->history; node; node = node->next)
	{
		my_putsfd(node->str, fd);
		my_putfd('\n', fd);
	}
	my_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
