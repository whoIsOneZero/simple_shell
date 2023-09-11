#include "myshell.h"

/**
 * prompt_user - displays  prompt to receive user input from terminal
 */
void prompt_user(void)
{
	write_out("#cisfun@user ");
	write(1, "\n", 1);
	write_out("$");
}
