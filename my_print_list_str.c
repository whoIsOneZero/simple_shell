#include "myshell.h"

/**
 * my_print_list_str - prints string of node element
 * @g: ptr to nod
 * Return: size for list
 */
size_t my_print_list_str(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		my_puts(g->str ? g->str : "(nil)");
		my_puts("\n");
		g = g->next;
		i++;
	}
	return (i);
}
