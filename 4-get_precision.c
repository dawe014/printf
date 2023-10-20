#include "main.h"

/**
 * getPrecision - Calculates the precision for printing
 * @f: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @l: list of arguments.
 *
 * Return: Precision.
 */
int getPrecision(const char *f, int *i, va_list l)
{
	int curr_i = *i + 1;
	int p = -1;

	if (f[curr_i] != '.')
		return (p);

	p = 0;

	for (curr_i += 1; f[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(f[curr_i]))
		{
			p *= 10;
			p += f[curr_i] - '0';
		}
		else if (f[curr_i] == '*')
		{
			curr_i++;
			p = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (p);
}
