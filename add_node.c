#include "myshell.h"

/**
 * add_node - adds a new node at the beginnig of a list...
 * ... of type 'list_t'
 * @head: double pointer to the head of the linked list
 * @str: new node to be added
 *
 * Return: pointer to the new node (SUCCESS)
 * or NULL (FAIL)
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new; /*pointer to the new node*/
	unsigned int len = 0;
	size_t size;

	while (str[len])
		len++; /*To get the string length*/

	size = list_len(*head);
	new = malloc(size);
	if (!new) /*Mem alloc. failed. Insufficient memory*/
		return (NULL);

	/*Allocate new mem. block and copy string*/
	new->str = strdup(str);

	new->len = len;

	/*'next' of new node should point to old head*/
	new->next = (*head);

	/*Change head to now point to 'new' node*/
	(*head) = new;

	return (*head);
}
