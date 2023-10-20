#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * printPointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int printPointer(va_list types, char b[],
	int f, int w, int p, int s)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	b[BUFF_SIZE - 1] = '\0';
	UNUSED(p);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		b[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f & F_PLUS)
		extra_c = '+', length++;
	else if (f & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (writePointer(b, ind, length,
		w, f, padd, extra_c, padd_start));
}

/**
 * printNonPrintable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printNonPrintable(va_list types, char b[],
	int f, int w, int p, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (isPrintable(str[i]))
			b[i + offset] = str[i];
		else
			offset += appendHexaCode(str[i], b, i + offset);

		i++;
	}

	b[i + offset] = '\0';

	return (write(1, b, i + offset));
}

/**
 * printReverse - Prints reverse string.
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int printReverse(va_list types, char b[],
	int f, int w, int p, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * printRotstring - Print a string in rot13.
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */
int printRotstring(va_list types, char b[],
	int f, int w, int p, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
