#include "myshell.h"

/**
 * my_get_history_file - get history file
 * @infos: check header
 *
 * Return:  string of history file
 */

char *my_get_history_file(info_t *infos)
{
	char *buf, *dir;

	dir = my_getenv(infos, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (my_strlen(dir) + my_strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	my_strcpy(buf, dir);
	my_strcat(buf, "/");
	my_strcat(buf, HIST_FILE);
	return (buf);
}
