#include "myshell.h"

/**
 * main - program entry
 *
 * Return: 0 (success)
 */
int main(void)
{
	prompt_user();
	write(1, "\n", 1);

	return (0);
}
