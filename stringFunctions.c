#include "main.h"

/**
 * _stcmp - compares two strings
 * @s1: source string
 * @s2: destination string
 * Return: returns destination string
 */

int _stcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}
/**
 * _putchar - function that writes a char to stdout
 * @c: character to be printed
 * Return: returns the number of bytes written 
 */
int _putchar(int c)
{
	return(write(1, &c, 1));
}
