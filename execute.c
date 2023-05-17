#include "main.h"

/**
 * execute - function to perform the execve
 * @cmd: the command with the arguments if present
 */
void execute(char **cmd)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		printf("Command not found\n");
	}
	else
		wait(NULL);
}
