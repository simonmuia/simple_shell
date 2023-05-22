#include "main.h"
#include <stdarg.h>

/**
 * myprintf - function that emulates the printf
 * @format: the formatted string
 */
void myprintf(char *format, ...)
{
	char *pointer = format, *string;
	int value;
	va_list argp;

	va_start(argp, format);
	while (*pointer)
	{
		if (*pointer == '%')
		{
			switch (*++pointer)
			{
				case 's':
					string = va_arg(argp, char *);
					while (*string)
						_putchar(*(string++));
					break;
				case 'd':
					value = va_arg(argp, int);
					print_int(value);
					break;
				default:
					_putchar(*pointer);
					break;
			}
		}
		else
			_putchar(*pointer);
		pointer++;
	}

}
