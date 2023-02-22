#include "main.h"

/**
 * location - finds the location from path
 *
 * @command: command that has been input
 * Return: NULL or the path
 */

char *location(char *command)
{
	char *path_env, *path, *path_cmd, *dir;
	size_t len;

	path_env = getenv("PATH");

	if (path_env == NULL)
	{
		return (NULL);
	}
	path = strdup(path_env);
	if (path == NULL)
	{
		return (NULL);
	}
