#include "main.h"

/**
 * input_to_cmd - function that tokenizes the string from the user
 * @line: the line to be tokenized
 * Return: returns an array of pointers to the commands
 */
char **input_to_cmd(char *line)
{
	int i = 0;
	char **args = NULL;

	args = malloc(sizeof(char *) * MAX_ARGS);
	if (args == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for args \n");
		exit(EXIT_FAILURE);
	}
	args[i] = strtok(line, " ");
	while (1)
	{
		i++;
		args[i] = strtok(NULL, " ");
		if (args[i] == NULL)
			break;
	}
	return (args);
}
