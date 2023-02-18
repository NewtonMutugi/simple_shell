#include "main.h"

/**
 * main - program entry point
 * Return: int
 */

int main(int ac, char **av)
{
	while(1)
	{
		printf("%s", prompt);
		read = getline(&command, &len, stin);

		if (read == -1)
		{
			perror("Error: ");
			return (1);
		}
	}
	return (0);
}
