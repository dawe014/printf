#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handleWriteC - Prints a string
 * @c: char types.
 * @b: Buffer array to handle print
 * @f:  Calculates active flags.
 * @w: get width.
 * @p: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int handlerWriteC(char c, char b[],
	int f, int w, int p, int s)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(p);
	UNUSED(s);

	if (f & F_ZERO)
		padd = '0';

	b[i++] = c;
	b[i] = '\0';

	if (w > 1)
	{
		b[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			b[BUFF_SIZE - i - 2] = padd;

		if (f & F_MINUS)
			return (write(1, &b[0], 1) +
					write(1, &b[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &b[BUFF_SIZE - i - 1], w - 1) +
					write(1, &b[0], 1));
	}

	return (write(1, &b[0], 1));
}

/**
 * writeNumbers - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: precision specifier
 * @s: Size specifier
 *
 * Return: Number of chars printed.
 */
int writeNumbers(int is_negative, int ind, char b[],
	int f, int w, int p, int s)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (f & F_PLUS)
		extra_ch = '+';
	else if (f & F_SPACE)
		extra_ch = ' ';

	return (writeNum(ind, b, f, w, p, length, padd, extra_ch));
}

/**
 * writeNum - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @b: Buffer
 * @f: Flags
 * @w: width
 * @p: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int writeNum(int ind, char b[], int f, int w, int p,
int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (p == 0 && ind == BUFF_SIZE - 2 && b[ind] == '0' && w == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (p == 0 && ind == BUFF_SIZE - 2 && b[ind] == '0')
		b[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (p > 0 && p < length)
		padd = ' ';
	while (p > length)
		b[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (w > length)
	{
		for (i = 1; i < w - length + 1; i++)
			b[i] = padd;
		b[i] = '\0';
		if (f & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[ind], length) + write(1, &b[1], i - 1));
		}
		else if (!(f & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[1], i - 1) + write(1, &b[ind], length));
		}
		else if (!(f & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				b[--padd_start] = extra_c;
			return (write(1, &b[padd_start], i - padd_start) +
				write(1, &b[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		b[--ind] = extra_c;
	return (write(1, &b[ind], length));
}

/**
 * writeUnsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @b: Array of chars
 * @f: Flags specifiers
 * @w: Width specifier
 * @p: Precision specifier
 * @s: Size specifier
 *
 * Return: Number of written chars.
 */
int writeUnsigned(int is_negative, int ind,
	char b[], int f, int w, int p, int s)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(s);

	if (p == 0 && ind == BUFF_SIZE - 2 && b[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (p > 0 && p < length)
		padd = ' ';

	while (p > length)
	{
		b[--ind] = '0';
		length++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';

	if (w > length)
	{
		for (i = 0; i < w - length; i++)
			b[i] = padd;

		b[i] = '\0';

		if (f & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &b[ind], length) + write(1, &b[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &b[0], i) + write(1, &b[ind], length));
		}
	}

	return (write(1, &b[ind], length));
}

/**
 * writePointer - Write a memory address
 * @b: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @w: Width specifier
 * @f: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int writePointer(char b[], int ind, int length,
	int w, int f, char padd, char extra_c, int padd_start)
{
	int i;

	if (w > length)
	{
		for (i = 3; i < w - length + 3; i++)
			b[i] = padd;
		b[i] = '\0';
		if (f & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			b[--ind] = 'x';
			b[--ind] = '0';
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[ind], length) + write(1, &b[3], i - 3));
		}
		else if (!(f & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			b[--ind] = 'x';
			b[--ind] = '0';
			if (extra_c)
				b[--ind] = extra_c;
			return (write(1, &b[3], i - 3) + write(1, &b[ind], length));
		}
		else if (!(f & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				b[--padd_start] = extra_c;
			b[1] = '0';
			b[2] = 'x';
			return (write(1, &b[padd_start], i - padd_start) +
				write(1, &b[ind], length - (1 - padd_start) - 2));
		}
	}
	b[--ind] = 'x';
	b[--ind] = '0';
	if (extra_c)
		b[--ind] = extra_c;
	return (write(1, &b[ind], BUFF_SIZE - ind - 1));
}
