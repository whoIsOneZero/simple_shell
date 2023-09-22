#include "myshell.h"

/**
 * my_read_buf - read buffer
 * @info: check header
 * @buf: buffer
 * @s: size
 *
 * Return: size
 */
ssize_t my_read_buf(info_t *info, char *buf, size_t *s)
{
	ssize_t r = 0;

	if (*s)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*s = r;
	return (r);
}
