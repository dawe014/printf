#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_str_rev - prints astring in reverse
 * @rev: string to print
 * Return: number of chars printed
*/
int print_str_rev(va_list rev)
{
	char *str;
	int i, j = 0;

	str = va_arg(rev, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(str[i]);
		j++;
	}
	return (j);
}
