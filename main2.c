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
	char *prompt = "cisfun $ ";
	char *cmdptr = NULL;
	size_t cmdlen = 0;
	ssize_t getline_result;

	while (1)
	{
		printf("%s", prompt);
		getline_result = getline(&cmdptr, &cmdlen, stdin);
		if (getline_result == -1)
		{
			printf("Exit..\n");
			return (-1);
		}

		char *cmd_cpy = strdup(cmdptr);
		if (cmd_cpy == NULL)
		{
			perror("Error:");
			continue;
		}

		char *token = strtok(cmd_cpy, delim);
		int arg_count = 0;
		while (token != NULL)
		{
			arg_count++;
			token = strtok(NULL, delim);
		}

		char **args = calloc(arg_count + 1, sizeof(char *));
		if (args == NULL)
		{
			perror("Error:");
			free(cmd_cpy);
			continue;
		}

		token = strtok(cmdptr, delim);
		int i = 0;
		while (token != NULL)
		{
			args[i++] = strdup(token);
			token = strtok(NULL, delim);
		}

		args[i] = NULL;

		execmd(args);

		for (i = 0; i < arg_count; i++)
		{
			free(args[i]);
		}

		free(args);
		free(cmd_cpy);
	}

	free(cmdptr);
	return (0);
}
