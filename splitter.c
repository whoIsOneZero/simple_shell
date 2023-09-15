#include "myshell.h"

/**
 * splitter - breaks the command into parts (tokenization)
 * @cmd: a pointer to the command input
 * @delim: a pointer to the delimiter for tokenization
 * @tokens: pointer to array to store the tokenized command
 * @max_tokens: max num of tokens array can hold
 *
 * Return: num of tokens found
 */
int splitter(char *cmd, const char *delim, char *tokens[], int max_tokens)
{
	char *part; /*Temporarily store parts of the command*/
	int num = 0; /*Number of tokens found*/

	/*Tokenize the input string*/
	part = strtok(cmd, delim);

	while (part != NULL && num < max_tokens)
	{
		/*Store the token in the array*/
		tokens[num] = part;
		num++;
		/*Continue tokenization*/
		part = strtok(NULL, delim);
	}

	return (num);
}
