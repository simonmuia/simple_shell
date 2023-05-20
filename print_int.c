#include "main.h"

/**
 * print_int - function that prints an integer
 * @value: the integer to be printed
 *
 */
void print_int(int value)
{
	int num = value;
	int divisor;

	if (value <= 9)
		_putchar(value + 48);
	else
	{
	divisor = 1;
	while (divisor <= num / 10)
		divisor *= 10;
	while (divisor > 0)
	{
		_putchar((num / divisor) + 48);
		num %= divisor;
		divisor /= 10;
	}
	}
}
