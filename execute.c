#include "main.h"

/**
 * execute - function to perform the execve
 * @filename: the filename, that is the executable file
 * @cmd: the command with the arguments if present
 * @line: the line number
 */
void execute(char *filename, char **cmd, int line)
{
	if (access(cmd[0], F_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == 0 && cmd[0] && cmd[0])
		{
			execve(cmd[0], cmd, NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	else if (cmd[0])
		printf("%s: %d: %s: not found\n", filename, line, cmd[0]);
}
