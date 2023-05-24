#include "main.h"

/**
 * myrllc - custom realloc
 * @pt: pointer to former alloc
 * @osize: old size
 * @nsize: new size
 * Return: block name
*/

void myrllc(void *pt, size_t osize, size_t nsize)
{
	void *npt = NULL;

	if (nsize == 0 )
	{
		free(pt);
		return (NULL);
	}
	if (nsize <= osize)
		return (pt);
	npt = malloc(nsize);
	if (!npt)
		return (NULL);
	
	mymemcpy(npt, pt, osize);
	free(pt);

	return (npt);
}

/**
 * mymemcpy - custom memcpy function
 * @dest: pointer to dest mem block
 * @src: pointer to source mem block
 * @n: number of bytes to copy
 * Return: pointer to destination mem block
*/

void *mymemcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	if (dest == NULL && src == NULL)
		return (NULL);
	
	while (n--)
		*d++ = *s++;
	
	return dest;
}

