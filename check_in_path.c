#include "myshell.h"

/**
 *
 */


int check_in_path(char *prog)
{


	list_t *path_head;
	char *path , *token,*full_path;
	struct stat st;


	path =strdup(_getenv("PATH"));
	path_head = malloc(sizeof(list_t));
	if (path != NULL)
	{

		token = strtok(path, ":");
		path_head -> str = strdup(token);
		token = strtok(NULL, ":");

		while (token != NULL)
		{
			add_node_end(&path_head, token);
			token = strtok(NULL, ":");
		}

	}
	for(;path_head != NULL; path_head = path_head ->next)
	{
		full_path = malloc(strlen(path_head->str) + strlen("/")
				   + strlen(prog) + 1);
		strcpy(full_path, path_head->str);

		strcat(full_path, "/");
		strcat(full_path, prog);

		if (stat(full_path, &st) == 0)
		{
			strcpy(prog,full_path);

			return (0);

		}
	free(full_path);


	}
	free(path);
	free_list(path_head);

	return (-1);

}
