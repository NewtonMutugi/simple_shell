#include "main.h"

/**
 * main - program entry point
 * @ac: command count
 * @av: argumrnt vectors
 * Return: int
 */

int main(int ac, char **av)
{
	while (1)
	{
		printf("%s", prompt);
		read = getline(&command, &len, stdin);

		if (read == -1)
		{
			perror("Error: ");
			return (1);
		}
	}
	return (0);
}
