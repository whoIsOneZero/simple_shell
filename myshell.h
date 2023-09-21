#ifndef MYSHELL_HEADER
#define MYSHELL_HEADER


/* structs implementations */

/**
 * struct liststr - singly linked list
 * @num: number
 * @str: string
 * @next: next node pointer
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - all important functions for diffrent parts of program,
 * @arg: getline resulted string
 * @argv: string array of arguments
 * @path: path of command
 * @env_changed: if environ changed
 * @status: return status for last exec
 * @cmd_buf: pointer of cmd_buf
 * @line_count: errors count
 * @err_num:  exit()s error code
 * @linecount_flag: checks on count
 * @fname: program filename
 * @env: environ as linked list
 * @environ: environ from LL env and modified
 * @history: node history
 * @alias: alias node
 * @cmd_buf_type: cmd buffer type ,OR ,AND;
 * @readfd: file descriptor to read input
 * @histcount: history of count line number
 * @argc: arguments count
 */
typedef struct passinfo
{
	char **cmd_buf;

	int cmd_buf_type;
	int readfd;
	int histcount;
	char *fname;
	int argc;
	char **argv;
	char *path;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	unsigned int line_count;
	int err_num;
	int linecount_flag;

	char *arg;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - the string and related to builtin
 * @func: function
 * @type: command flag
 */
typedef struct builtin
{
	int (*func)(info_t *);
	char *type;

} builtin_table;


/*---> HEADER FILES <---*/
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/*---> CONSTANTS & Macros <---*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*---> SOME MORE <---*/
#define CMD_AND		2
#define CMD_OR		1
#define CMD_NORM	0
#define CMD_CHAIN	3

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

/*__- conversion of number__-*/
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/*---> Used in loop <--*/
void my_find_cmd(info_t *);
void my_fork_cmd(info_t *);
int my_find_builtin(info_t *);
int my_hsh(info_t *, char **);

/*---> shell loop <--*/
int my_loophsh(char **);



/*--> custoM string.h implemetation <--*/
int my_strcmp(char *, char *);
int my_strlen(char *);
char *my_strcat(char *, char *);
char *my_starts_with(const char *, const char *);

void my_puts(char *);
char *my_strcpy(char *, char *);
char *my_strdup(const char *);
int my_putchar(char);

/*--> TOKENIZATION <--*/
char **my_strtow2(char *, char);
char **my_strtow(char *, char *);

/*--> Memory management <--*/
int my_bfree(void **);
void my_ffree(char **);
char *my_memset(char *, char, unsigned int);
void *my_realloc(void *, unsigned int, unsigned int);


/*---> Exit the shell <--*/
char *my_strncat(char *, char *, int)
char *my_strchr(char *, char);
char *my_strncpy(char *, char *, int);


/*---> FUNCTION PROTOTYPES <---*/
size_t my_list_len(const list_t *head);
int my_interactive(info_t *);
int my_is_delim(char chr, char *delim);
int my_isalpha(int chr);




char **my_list_to_strings(list_t *_head);
char *my_find_path(info_t *info, char *path, char *prog);
char *my_dup_chars(char *path, int from, int to);
char *my_memset(char *fill, char byte, unsigned int num);
void my_ffree(char **ptr);
list_t *my_node_starts_with(list_t *head, char *pref, char after);
int my_is_cmd(info_t *inform, char *path);
ssize_t my_get_node_index(list_t *head, list_t *node);



/*---> MEMORY MANAGEMENT <--*/
int my_bfree(void **p);

#endif /*MYSHELL_HEADER*/
