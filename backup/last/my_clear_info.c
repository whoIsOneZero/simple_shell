#include "myshell.h"

/**
 * my_clear_info - clear info_t
 * @infos: address
 */
void my_clear_info(info_t *infos)
{
	infos->arg = NULL;
	infos->argv = NULL;
	infos->path = NULL;
	infos->argc = 0;
}
