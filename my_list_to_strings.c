#include "myshell.h"

/**
 * my_list_to_strings - converts Linked list(string) to Array(of strings).dd
 * @_head: a pointer to the _head (node1) .dd
 * Return: Derived array of String.dd
 */

char **my_list_to_strings(list_t *_head)
{
	list_t *curr_node = _head;
	size_t index, num_nodes;
	char **a_str; /*The converted array of strings*/
	char *curr_str; /*The current string*/

	num_nodes = my_list_len(_head);
	if (!_head || !num_nodes)
		return (NULL);

	a_str = malloc(sizeof(char *) * (num_nodes + 1));
	if (!a_str)
		return (NULL);
	for (num_nodes = 0; curr_node; curr_node = curr_node->next, num_nodes++)
	{
		curr_str = malloc(my_strlen(curr_node->str) + 1);
		if (!curr_str)
		{
			for (index = 0; index < num_nodes; index++)
				free(a_str[index]);
			free(a_str);
			return (NULL);
		}

		curr_str = my_strcpy(curr_str, curr_node->str);
		a_str[num_nodes] = curr_str;
	}
	a_str[num_nodes] = NULL;
	return (a_str);
}
