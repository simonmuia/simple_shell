#include "main.h"

/**
 * execute - function to perform the execve
 * @filename: the filename, that is the executable file
 * @cmd: the command with the arguments if present
 * @line: the line number
 */
void execute(char *filename, char **cmd, int line)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (access(cmd[0], F_OK) == 0)
			execve(cmd[0], cmd, NULL);
		printf("%s: %d: %s: not found\n", filename, line, cmd[0]);
	}
	else
		wait(NULL);
}
