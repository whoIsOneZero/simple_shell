#include "myshell.h"

/**
 * my_print_error - error massage print
 * @infos: check header
 * @estr: string of error type
 * Return: converted number , else 0
 */
void my_print_error(info_t *infos, char *estr)
{
	my_eputs(infos->fname);
	my_eputs(": ");
	my_print_d(infos->line_count, STDERR_FILENO);
	my_eputs(": ");
	my_eputs(infos->argv[0]);
	my_eputs(": ");
	my_eputs(estr);
}
