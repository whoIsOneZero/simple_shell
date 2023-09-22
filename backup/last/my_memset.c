#include "myshell.h"

/**
 * my_memset - fills a block of memory wITh a ConStant byte, a num of times
 * @num: nUmber of bytes you want to fiLl. dd.
 * @fill: the MemoRy area you want to fill. dd.
 * @byte: Byte vallUe to be Used for filLing
 * Return: ptr to e fillEd memory area
 */
char *my_memset(char *fill, char byte, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		fill[i] = byte;
	return (fill);
}
