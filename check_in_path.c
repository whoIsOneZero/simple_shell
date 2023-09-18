#include "myshell.h"
/**
 * check_in_path - checks whether the program exists in the PATH env
 * @prog: the program to check for
 * Return: 0 (proram found), or -1 otherwise
 */
int check_in_path(char *prog)
{
	list_t *path_head, *temp;
	char *path, *token, *full_path;
	struct stat st;

	path = strdup(_getenv("PATH"));
	path_head = malloc(sizeof(list_t));
	if (path != NULL)
	{
		token = strtok(path, ":");
		path_head->str = strdup(token);
		path_head->next = NULL;
		token = strtok(NULL, ":");
		while (token != NULL)
		{
			add_node_end(&path_head, token);
			token = strtok(NULL, ":");
		}
	} temp = path_head;
	for (; temp != NULL; temp = temp->next)
	{
		full_path = malloc(_strlen(path_head->str) + _strlen("/")
				   + _strlen(prog) + 1);
		strcpy(full_path, temp->str);
		strcat(full_path, "/");
		strcat(full_path, prog);
		if (stat(full_path, &st) == 0)
		{
			strcpy(prog, full_path);
			free(full_path);
			free(path);
			free(token);
			free_list(path_head);
			return (0);
		}
		free(full_path);
	}
	free(path);
	free_list(path_head);
	free(token);
	return (-1);
}
