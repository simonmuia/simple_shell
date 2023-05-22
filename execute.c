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
		char *env_path = getenv("PATH");
		char *path = strdup(env_path);
		char *directory = strtok(path, ":");

		while (directory && found == 0)
		{
			char cmd_path[24];

			strcpy(cmd_path, directory);
			strcat(cmd_path, "/");
			strcat(cmd_path, cmd[0]);
			if (access(cmd_path, F_OK) == 0)
			{
				found = 1;
				pid = fork();
				if (pid == 0)
					execve(cmd_path, cmd, NULL);
				else
					wait(NULL);
			}
			directory = strtok(NULL, ":");
		}
		free(path);
	}
	if (found == 0 && cmd[0])
		myprintf("%s: %d: %s: not found\n", filename, line, cmd[0]);
	free(cmd[0]);
}
