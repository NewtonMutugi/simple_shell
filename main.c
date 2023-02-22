#include "main.h"

/**
 * main - code entry point
 *
 * @ac: number of arguments
 * @argv: array of arguments
 * Return: 0 for success
 */

int main(int ac, char **argv)
{
	char *prompt = "cisfun $ ", *cmdptr, *token, *cmd_cpy, **args;
	size_t cmdlen = 0;
	ssize_t getline_result;
	int tkn_num = 0, i = 0;

	while (1)
	{
		printf("%s", prompt);
		getline_result = getline(&cmdptr, &cmdlen, stdin);
		if (getline_result == -1)
		{
			printf("Exit..\n");
			return (-1);
		}
		cmd_cpy = strdup(cmdptr);
		if (cmd_cpy == NULL)
		{
			perror("Error:");
			continue;
		}
