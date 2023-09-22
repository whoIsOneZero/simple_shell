#include "myshell.h"

/**
 * read_history - from file
 * @infos: check header.
 * Return: counts,otherwise 0
 */

int read_history(info_t *infos)
{
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	int i, last = 0, linecount = 0;
	char *buf = NULL, *filename = my_get_history_file(infos);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			my_build_history_list(infos, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		my_build_history_list(infos, buf + last, linecount++);
	free(buf);
	infos->histcount = linecount;
	while (infos->histcount-- >= HIST_MAX)
		my_delete_node_at_index(&(infos->history), 0);
	my_renumber_history(infos);
	return (infos->histcount);
}
