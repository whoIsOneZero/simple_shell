#include "myshell.h"

/**
 * my_history - show history list line by linee
  * @infos: check header,general info
  *  Return: Always 0
 */

int my_history(info_t *infos)
{
	my_print_list(infos->history);

	return (0);
}
