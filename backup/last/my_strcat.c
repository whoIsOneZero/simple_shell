/**
 * my_strcat - to concatenate 2 strings. dd.
 * @dest: where to concatenate to (buffer)
 * @src: where to concatenate from (buffer).
 * Return: a pointer to the concatenated string (buffer).
 */
char *my_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

