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

		write(1, filename, _strlen(filename));
		write(1, ": ", 2);
		/* check on how to convert inttostr function */
		write(1, line, _strlen(line));
		write(1, ": ", 2);
		write(1, cmd[0], _strlen(cmd[0]));
		write(1, ": ", 2);
		write(1, "not found\n", 10);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
