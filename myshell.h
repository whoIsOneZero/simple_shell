#ifndef MYSHELL_HEADER
#define MYSHELL_HEADER


/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


/*---> HEADER FILES <---*/
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/*---> CONSTANTS <---*/
#define MAX_ARGS 512
#define MAX_TOKENS 512

/*---> FUNCTION PROTOTYPES <---*/
void write_out(const char *the_msg);
void prompt_user(void);
char *get_cmd(void);
int run_prog(const char *prog, char *const args[], char *const env[]);
int splitter(char *cmd, const char *delim, char *tokens[], int max_tokens);
char *_getenv(const char *name);
int check_in_path(char *prog);


list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
size_t print_list(const list_t *h);

/* string.h implemetation */
int _strlen(char *);
int _strcmp(char *, char *);

#endif /*MYSHELL_HEADER*/
