
#include "myshell.h"

/**
 * my_convert_number - like itoa
 * @numb: number to convert
 * @base: base of it
 * @flags: args flags
 *
 * Return: the string
 */
char *my_convert_number(long int numb, int base, int flags)
{
	static char *array;
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long n = numb;

	if (!(flags & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
