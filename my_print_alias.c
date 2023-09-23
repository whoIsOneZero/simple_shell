#include "myshell.h"

/**
 * my_print_alias - prints alias
 * @node: alias  node
 * Return:  0 , 1 on error
 */
int my_print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = my_strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		my_putchar(*a);
		my_putchar('\'');
		my_puts(p + 1);
		my_puts("'\n");
		return (0);
	}
	return (1);
}
