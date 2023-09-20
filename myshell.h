#ifndef MYSHELL_HEADER
#define MYSHELL_HEADER


/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


/*---> HEADER FILES <---*/
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
#define MAX_ARGS 64
#define MAX_TOKENS 64

/*---> FUNCTION PROTOTYPES <---*/
void write_out(const char *the_msg);
void prompt_user(void);
char *get_cmd(void);
int run_prog(char *prog, char *const args[], char *const env[]);
int splitter(char *cmd, const char *delim, char *tokens[], int max_tokens);
char *_getenv(const char *name);
int check_in_path(char *prog);
void intToString( int num, char* str);
void print_not_found(char *av,int counter, char *command);


/*---> SINGLY LINKED LIST FUNCS. <---*/
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
/*size_t print_list(const list_t *h);*/


/* string.h implemetation */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strdup(const char *str);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, char *src);


#endif /*MYSHELL_HEADER*/
