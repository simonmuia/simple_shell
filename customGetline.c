#include "main.h"
/**
 * _getline - gets user input
 * @lineptr: address of buffer where input is stored
 * @n: initial buffer size
 * @stream: pointer to FILE structure rep input stream
 * Return: reading position where next char is stored
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL ||  n == NULL || stream == NULL)
		return (-1);
	
	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	size_t pos = 0;
	int c;

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos >= *n - 1)
		{
			size_t new_size = *n + BUFFER_SIZE;
			char *new_ptr = (char *)realloc(*lineptr, new_size);
			if (new_ptr == NULL)
				return (-1);
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[pos++] = c;

		if ( c == '\n')
			break;
	}

	(*lineptr)[pos] = '\0';

	if (pos == 0 && c == EOF)
		return (-1);

	return (pos);
}



