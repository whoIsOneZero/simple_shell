#include "myshell.h"

void prompt_user(void)
{
	write_out("#cisfun@user ");
	write(1, "\n", 1);
	write_out("$");
}
