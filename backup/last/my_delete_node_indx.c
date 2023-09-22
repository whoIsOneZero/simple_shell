#include "myshell.h"


/**
 * my_delete_node_at_index - delete node at index
 * @head:  head node
 * @index: index to delete
 *
 * Return: 1 ,on failure 0
 */


int my_delete_node_at_index(list_t **head, unsigned int index)
{
	unsigned int i = 0;
	list_t *node, *prev_node;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
