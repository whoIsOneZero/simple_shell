#ifndef MYSHELL_HEADER
#define MYSHELL_HEADER

/*---> HEADER FILES <---*/
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*---> FUNCTION PROTOTYPES <---*/
void write_out(const char *the_msg);
void prompt_user(void);

#endif /*MYSHELL_HEADER*/
