#include "myshell.h"

/**
 * main - where the program starts
 * @argc: number of arguments passed
 * @argv: An array of strings of arguments
 * Return: [SUCCESS] - 0; [FAILURE] - 1
 */

int main(int argc, char **argv)
{
	info_t info[] = { INFO_INIT }; /*Initialized the field*/
	int file_d = 2; /*File descriptor*/

	/*Move value of fd and add 3*/
	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (file_d)
			: "r" (file_d));

	if (argc == 2) /*If an actual comman was passed afer ./hsh*/
	{
		file_d = open(argv[1], O_RDONLY);/*Open the prog (command)*/
		if (file_d == -1)/*handle the error*/
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				my_eputs(argv[0]);
				my_eputs(": 0: Can't open ");
				my_eputs(argv[1]);
				my_eputchar('\n');
				my_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = file_d;
	}
	/*Set up shell and execute functionality*/
	my_populate_env_list(info);
	my_read_history(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
