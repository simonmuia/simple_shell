#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - the main function
 * @argc: argument count
 * @argv: argument vector
 * Return: returns 0 on success
 */
int main(int argc, char **argv)
{
	char *line;
	size_t length;
	int string_length;

	while (1)
	{
		line = NULL;
		length = 0;
		string_length = 0;

		write(1, "prompt> ", 8);
		if (getline(&line, &length, stdin) != -1)
		{
			while (line[string_length] != '\0')
				string_length++;
			if (line[string_length - 1] == '\n')
				line[string_length - 1] = '\0';
		}
		free(line);
	}
	return (0);
}
