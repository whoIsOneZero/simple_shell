#include "myshell.h"

/**
 * my_get_node_index - what's the index of that node in the linked list
 * @head: Ptr to the first node in the linked list
 * @node: The particular Node whose index you want
 * Return: [Success] - node index; [Node not found] -1
 */
ssize_t my_get_node_index(list_t *head, list_t *node)
{
	size_t a; /*Keeps track of the index*/

	a = 0;

	while (head != NULL)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}

	/*Loop exited so node not found*/
	return (-1);
}
