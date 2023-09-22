#include "myshell.h"

/**
 * my_sigintHandler - stops C-C
 * @sig_num: signal number
 */
void my_sigintHandler(__attribute__((unused))int sig_num)
{
	my_puts("\n");
	my_puts("$ ");
	my_putchar(BUF_FLUSH);
}
