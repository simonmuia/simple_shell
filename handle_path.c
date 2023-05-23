#include "main.h"

/**
 * path_handler - concatanates a user command with the respective directory
 * @command: the command
 * @flag: a flag to keep record if command is found
 * Return: returns the flag
 */
int path_handler(char **command, int flag)
{
	pid_t pid;

	char *env_path = getenv("PATH");
	char *path = str_dup(env_path);
	char *directory = strtok(path, ":");

	while (directory && flag == 0)
	{
		char cmd_path[24];

		str_cpy(cmd_path, directory);
		str_cat(cmd_path, "/");
		str_cat(cmd_path, command[0]);
		if (access(cmd_path, F_OK) == 0)
		{
			flag = 1;
			pid = fork();
			if (pid == 0)
				execve(cmd_path, command, NULL);
			else
				wait(NULL);
		}
		directory = strtok(NULL, ":");
	}
	free(path);
	return (flag);
}
