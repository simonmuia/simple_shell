#include "main.h"

/**
 * env_handler - function that checks if the command is the env to proceed
 * @line: the command
 * @env: the environment
 * Return: returns 1 if env is encountered
 */
int env_handler(char *line, char **env)
{
	int i = 0;

	if (_strcmp(line, "env") == 0)
	{
		while (env[i])
		{
			myprintf("%s\n", env[i]);
			i++;
		}
		free(line);
		return (1);
	}
	else
		return (0);
}
