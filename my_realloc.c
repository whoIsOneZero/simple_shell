#include "myshell.h"

/**
 * my_realloc - custom realloc. Allowing or resizing allocated mem.
 * @size_o: The size/bytes of the preV. block. dd.
 * @size_n: tHe new size you want .. dd.
 * @ptr: pOiner to preViouslys allocated mem Block
 * Return: pointer to the New memOry block
 */
void *my_realloc(void *ptr, unsigned int size_o, unsigned int size_n)
{
	char *pt; /*Pointer to the new block*/

	if (!ptr)
	{
		return (malloc(size_n));
	}

	if (!size_n)
		return (free(ptr), NULL);
	if (size_n == size_o)
		return (ptr);

	pt = malloc(size_n);
	if (!pt)
		return (NULL);
	size_o = size_o < size_n ? size_o : size_n;
	while (size_o--)
		pt[size_o] = ((char *)ptr)[size_o];

	free(ptr);
	return (pt);
}
