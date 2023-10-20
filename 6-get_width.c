#include "main.h"

/**
 * getWidth - Calculates the width for printing
 * @f: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @l: list of arguments.
 *
 * Return: width.
 */
int getWidth(const char *f, int *i, va_list l)
{
	int curr_i;
	int w = 0;

	for (curr_i = *i + 1; f[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(f[curr_i]))
		{
			w *= 10;
			w += f[curr_i] - '0';
		}
		else if (f[curr_i] == '*')
		{
			curr_i++;
			w = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (w);
}
