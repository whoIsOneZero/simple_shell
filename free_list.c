#include "myshell.h"
/**
 * free_list - frees a linked list from memory
 * @head: pointer to the head of the linked list
 */
void free_list(list_t *head)
{
	list_t *temp; /*temporarily store next node's address...*/
	/*... while deallocating memory for the current one*/

	/*Traverse the list until head points to null*/
	while (head)
	{
		temp = head->next; /*Store next node's address*/
		free(head->str); /*Free data portion of the node*/
		free(head); /*Free e the current node iteself*/
		head = temp; /*Head now points to the next node*/
	}
}
