#include "myshell.h"

/**
 * prompt_user - displays  prompt to receive user input from terminal
 */
char* prompt_user(void)
{
	char *prompt = "#cisfun$ ";

	write_out(prompt);

	return(prompt);
}
