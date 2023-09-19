#include "myshell.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: a double pointer to the current list head
 * @str:  pointer to the string to be added (new node)
 *
 * Return: pointer to the new (last) node (SUCCESS)
 * or NULL (FAIL)
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end, *ptr;
	unsigned int len = 0;
	size_t size;

	ptr = *head; /*so that you can traverse the linked list*/

	while (str[len])
		len++;

	size = list_len(*head);
	end = malloc(size);
	if (!end) /*Mem. alloc. failed*/
		return (NULL);

	/*Initialize the new node*/
	end->str = strdup(str);
	end->len = len;
	end->next = NULL; /*It's a lone node at this point*/

	/*Check if linked list is empty*/
	/*Add new node to the beginning (end) if empty*/
	if (*head == NULL)
	{
		*head = end;
		return (end);
	}

	/**
	 * Traverse the linked list till the link (next) part...
	 * ... points to null (end of linked list)
	 */
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = end;

	return (end);
}
