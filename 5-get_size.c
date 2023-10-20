#include "main.h"

/**
 * getSize - Calculates the size to cast the argument
 * @f: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int getSize(const char *f, int *i)
{
	int curr_i = *i + 1;
	int s = 0;

	if (f[curr_i] == 'l')
		s = S_LONG;
	else if (f[curr_i] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (s);
}
