#include "main.h"

/**
 * str_dup - duplicates a string
 * @str: string to duplicate
 * Return: duplicated string
 */

char *str_dup(const char *str)
{
	if (str == NULL)
		return (NULL);

	size_t len = _strlen(str);

	/* Allocate memory*/
	char *dup = malloc((len + 1) * sizeof(char));

	if (dup != NULL)
	{
		str_cpy(dup, str);
	}

	return (dup);
}

/**
 * str_cpy - copies a string
 * @src: string to copy
 * @dest: destination string
 * Return: copied string
 */

char *str_cpy(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
		return (NULL);

	char *dest_start = dest;

	while (*src != '\0')
		*dest++ = *src;

	*dest = '\0';
	return (dest_start);
}

/**
 * str_cat - concatenates a string
 * @dest: second string
 * @src: first string
 * Return: concat string
 */

char *str_cat(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
		return (NULL);

	char *dest_start = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';

	return (dest_start);
}
