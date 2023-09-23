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
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
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
	char *type;
	int (*func)(info_t *);


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
#include <stddef.h>

/*---> CONSTANTS <---*/
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
char *my_strncat(char *, char *, int);
char *my_strchr(char *, char);
char *my_strncpy(char *, char *, int);


/*---> FUNCTION PROTOTYPES <---*/
size_t my_list_len(const list_t *head);
int my_interactive(info_t *);
int my_is_delim(char chr, char *delim);
int my_isalpha(int chr);

char **my_list_to_arr(list_t *_head);
int my_exit(info_t *infos);
int my_help(info_t *infos);
int my_cd(info_t *infos);
int my_history(info_t *infos);
int my_set_alias(info_t *infos, char *str);
int my_print_alias(list_t *node);
int my_alias(info_t *infos);
int my_env(info_t *infos);
char *my_getenv(info_t *infos, const char *name);
int _mysetenv(info_t *infos);
int _myunsetenv(info_t *infos);

int my_populate_env_list(info_t *infos);
void my_eputs(char *str);
int my_eputchar(char chr);
int my_putfd(char chr, int fd);
int my_putsfd(char *s, int fd);
int my_erratoi(char *str);
void my_print_error(info_t *infos, char *estr);
int my_print_d(int input, int fd);
char *my_convert_number(long int numb, int base, int flags);
void my_remove_comments(char *buf);

char **my_list_to_strings(list_t *_head);
char *my_find_path(info_t *info, char *path, char *prog);
char *my_dup_chars(char *path, int from, int to);
char *my_memset(char *fill, char byte, unsigned int num);
void my_ffree(char **ptr);
list_t *my_node_starts_with(list_t *head, char *pref, char after);
int my_is_cmd(info_t *inform, char *path);
ssize_t my_get_node_index(list_t *head, list_t *node);
char *my_strncpy(char *dest, char *src, int n);
char *my_strchr(char *str, char c);
ssize_t my_input_buf(info_t *infos, char **buf, size_t *len);
ssize_t my_get_input(info_t *infos);
ssize_t my_read_buf(info_t *info, char *buf, size_t *s);
int my_getline(info_t *infos, char **ptr, size_t *length);
void my_sigintHandler(__attribute__((unused))int sig_num);

int my_unsetenv(info_t *infos, char *var);
int my_setenv(info_t *infos, char *var, char *value);

char **my_get_environ(info_t *infos);
void my_clear_info(info_t *infos);
void my_set_info(info_t *infos, char **av);
void my_free_info(info_t *infos, int all);
char *my_get_history_file(info_t *infos);
void my_free_info(info_t *infos, int all);
int my_write_history(info_t *infos);
int my_read_history(info_t *infos);
int my_build_history_list(info_t *infos, char *buf, int linecount);
int my_renumber_history(info_t *infos);
list_t *my_add_node(list_t **head, const char *str, int num);
list_t *my_add_node_end(list_t **head, const char *str, int num);
size_t my_print_list_str(const list_t *g);
int my_delete_node_at_index(list_t **head, unsigned int index);
void my_free_list(list_t **head_ptr);


size_t my_print_list(const list_t *head);
void my_check_chain(info_t *inf, char *buff, size_t *p, size_t h, size_t len);
int my_is_chain(info_t *inform, char *buffer, size_t *pos);
int my_replace_alias(info_t *inf);
int my_replace_vars(info_t *inf);
int my_replace_string(char **old, char *nw);
int my_unset_alias(info_t *infos, char *str);

/* string.h implemetation */

/*---> MEMORY MANAGEMENT <--*/
int my_bfree(void **p);

#endif /*MYSHELL_HEADER*/
