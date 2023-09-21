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
 * @type: command flag
 * @func: function
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

/*---> CONSTANTS <---*/

/*---> FUNCTION PROTOTYPES <---*/
size_t my_list_len(const list_t *head);
int my_interactive(info_t *);
int my_is_delim(char chr, char *delim);
int my_isalpha(int chr);

char **my_list_to_arr(list_t *_head);
list_t *my_node_starts(list_t *head, char *pref, char after)

/* string.h implemetation */





#endif /*MYSHELL_HEADER*/
