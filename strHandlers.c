#include "main.h"

/**
 * str_dup - duplicates a string
 * @str: string to duplicate
 * Return: duplicated string
 */

char *str_dup(const char *str)
{
	size_t len;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	/* Allocate memory*/
	dup = malloc((len + 1));

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
	char *dest_start;

	dest_start = dest;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (*src != '\0')
		*dest_start++ = *src++;

	*dest_start++ = '\0';
	return (dest_start);
}

/**
 * str_cat - concatenates a string
 * @dest: second string
 * @src: first string
 * Return: concat string
 */

char *str_cat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest++ = '\0';
	*dest = *src;

	return (temp);
}
