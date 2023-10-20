#include "main.h"

void printBuffer(char b[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int f, w, p, s, buff_ind = 0;
	va_list l;
	char b[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			b[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				printBuffer(b, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			printBuffer(b, &buff_ind);
			f = getFlags(format, &i);
			w = getWidth(format, &i, l);
			p = getPrecision(format, &i, l);
			s = getSize(format, &i);
			++i;
			printed = handlePrint(format, &i, l, b,
				f, w, p, s);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	printBuffer(b, &buff_ind);

	va_end(l);

	return (printed_chars);
}

/**
 * printBuffer - Prints the contents of the buffer if it exist
 * @b: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void printBuffer(char b[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &b[0], *buff_ind);

	*buff_ind = 0;
}
