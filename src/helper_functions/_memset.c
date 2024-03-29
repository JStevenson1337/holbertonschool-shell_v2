#include "../include/shell.h"
/**
 * _memset - function start
 * @s: pointer to memory location
 * @b: constant bytes
 * @n: number of bytes
 * Description: function that fills memory with a constant byte.
 * Return: mutated string
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);

}
