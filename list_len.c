#include "myshell.h"
/**
 * list_len - calcs. the num. of elements in a list, type 'list_t'
 * @h: a pointer to the head of the linked list
 *
 * Return: number of elements
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str) /*Not null*/
			count++;
		h = h->next;
	}
	return (count);
}
