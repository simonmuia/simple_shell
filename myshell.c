#include "main.h"
/**
 * main - the main function
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 * Return: returns 0 on success
*/
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *line = "", **cmd_args;
	size_t length;
	int string_length, line_count = 0;
	char *filename =  argv[0];

	while (1)
	{
		line = NULL;
		length = 0;
		string_length = 0;
		line_count++;
		write(1, "prompt> ", 8);
		if (_getline(&line, &length, stdin) > 0)
		{
			if (_strcmp(line, "") == 0)
			{
				continue;
			}
			while (line[string_length] != '\0')
				string_length++;
			line[string_length - 1] = '\0';
			exit_handler(line);
			if (env_handler(line, env))
				continue;
			if (_strcmp(line, "") != 0)
			{
				cmd_args = input_to_cmd(line);
				execute(filename, cmd_args, line_count);
			}
			free(cmd_args);
		}
		if (!isatty(0))
			break;
	}
	return (0);
}
