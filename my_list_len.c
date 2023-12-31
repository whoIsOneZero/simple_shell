#include "myshell.h"

/**
 * my_list_len - To Calc length (size) of a linked list. dd.
 * @head: A pointer to the head of the Linked List. dd.
 * Return: calc'ed Size of the linked List. dd.
 */

size_t my_list_len(const list_t *head)
{
	size_t size;

	size = 0;

	for (; head; head = head->next) /*Move to next node till NULL reach*/
	{
		size++;
	}

	return (size);
}
