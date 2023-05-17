#include "main.h"

/**
 * main - the main function
 * @argc: argument count
 * @argv: argument vector
 * Return: returns 0 on success
 */
int main(int argc, char **argv)
{
	char *line, **cmd_args;
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
		if (getline(&line, &length, stdin) != -1)
		{
			while (line[string_length] != '\0')
				string_length++;
			line[string_length - 1] = '\0';
			if (strcmp(line, "exit") == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			cmd_args = input_to_cmd(line);
			execute(filename, cmd_args, line_count);
		}
		free(line);
		if (!isatty(0))
			break;
	}
	free(cmd_args);
	return (0);
}
