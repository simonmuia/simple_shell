#include "main.h"

/**
 * exit_handler - function that checks if command is exit to proceed
 * @line: the command
 */
void exit_handler(char *line)
{
	if (_strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
}
