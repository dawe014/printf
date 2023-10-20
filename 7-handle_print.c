#include "main.h"
/**
 * handlePrint - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @b: Buffer array to handle print.
 * @f: Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: 1 or 2;
 */
int handlePrint(const char *fmt, int *ind, va_list list, char b[],
	int f, int w, int p, int s)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', printCharacter}, {'s', printString}, {'%', printPercentage},
		{'i', printInteger}, {'d', printInteger }, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printHexaDecimal},
		{'X', printHexaUpper}, {'p', printPointer}, {'S', printNonPrintable},
		{'r', printReverse}, {'R', printRotstring}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, b, f, w, p, s));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
