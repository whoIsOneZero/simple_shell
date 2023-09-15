#include "lists.h"

/**
 * print_list - prints all elemnts of list_t list
 * @h: ponter to the list
 * Return: number of nodes
 *
 */





size_t print_list(const list_t *h)
{
	size_t size = 0;

	while (h)
	{
		size += 1;
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;


	}

	return (size);



}
