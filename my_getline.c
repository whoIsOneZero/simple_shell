#include "myshell.h"

/**
 * my_getline - get input from stdin
 * @infos: check header
 * @ptr: pointer to buffer
 * @length: size of buffer
 * Return: input as string
 */
int my_getline(info_t *infos, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	char *p = NULL, *new_p = NULL, *c;
	ssize_t r = 0, s = 0;
	static size_t len, i;
	size_t k;

	p = *ptr;

	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = my_read_buf(infos, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = my_strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = my_realloc(p, s, s ? s + k : k + 1);

	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		my_strncat(new_p, buf + i, k - i);
	else
		my_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
