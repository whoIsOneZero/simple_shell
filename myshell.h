#ifndef MYSHELL_HEADER
#define MYSHELL_HEADER

/*---> HEADER FILES <---*/
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/*---> FUNCTION PROTOTYPES <---*/
void write_out(const char *the_msg);
void prompt_user(void);
char *get_cmd(void);
int run_prog(const char *prog, char *const args[], char *const env[]);

#endif /*MYSHELL_HEADER*/
