#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t\r\n\a"

/**
 * tokenize - tokenizes input
 *
 * @input: command
 * Return: char
 */

char **tokenize(char *input)
{
	char *copy = strdup(input);

	if (copy == NULL)
	{
		perror("Error: ");
		return (NULL);
	}

	int arg_count = 0;
	char *token = strtok(copy, DELIM);

	while (token != NULL)
	{
		arg_count++;
		token = strtok(NULL, DELIM);
	}

	char **args = calloc(arg_count + 1, sizeof(char *));

	if (args == NULL)
	{
		perror("Error: ");
		free(copy);
		return (NULL);
	}

	int i = 0;

	token = strtok(input, DELIM);
	while (token != NULL)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, DELIM);
	}
	args[i] = NULL;

	free(copy);

	return (args);
}

/**
 * main - code entry point
 *
 * @ac: number of arguments
 * @argv: array of arguments
 * Return: 0 for success
 */

int main(int ac, char **argv)
{
	char *cmdptr, *cmd_cpy;
	size_t cmdlen = 0;
	ssize_t getline_result;
	int tkn_num = 0;
	char *token;
	int i;

	while (1)
	{
		printf("%s", "cisfun $ ");
		getline_result = getline(&cmdptr, &cmdlen, stdin);
		if (getline_result == -1)
		{
			printf("Exit..\n");
			return (-1);
		}

		char **args = tokenize(cmdptr);

		if (args == NULL)
		{
			continue;
		}

		execmd(args);

		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);

		free(cmdptr);
		cmdptr = NULL;
		cmdlen = 0;
	}
	return (0);
}
