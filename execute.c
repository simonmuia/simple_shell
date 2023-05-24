#include "main.h"

/**
 * execute - function to perform the execve
 * @filename: the filename, that is the executable file
 * @cmd: the command with the arguments if present
 * @line: the line number
 */
void execute(char *filename, char **cmd, int line)
{
	int found = 0, pid;

	if (access(cmd[0], F_OK) == 0)
	{
		pid = fork();
		found = 1;

		if (pid == 0)
			execve(cmd[0], cmd, NULL);
		else
			wait(NULL);
	}
	if (cmd[0] && found == 0)
	{
		found = path_handler(cmd, found);
	}
	if (found == 0 && cmd[0])
		myprintf("%s: %d: %s: No such file or directory\n", filename, line, cmd[0]);
	free(cmd[0]);
}
