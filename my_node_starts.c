#include "myshell.h"

/**
 * my_node_starts_with - find which nodes starts with this prefix. dd.
 * @head: A pointer to the head of the Linked list
 * @pref: what the matching to to be done against. dd.
 * @after: charac just after the prefix which is to be matched. dd.
 * Return: ptr to matching node (match found) OR NULL (not match found)
 */

list_t *my_node_starts_with(list_t *head, char *pref, char after)
{
	char *ptr = NULL;

	while (head)
	{
		ptr = my_starts_with(head->str, pref);
		/*Above returns NULL if no match found*/

		if (ptr && ((after == -1) || (*ptr == after)))
			return (head); /*Match found, pointer to that node*/

		/*Next iteration*/
		head = head->next;
	}

	/*Loop completed so no match found*/
	return (NULL);
}
