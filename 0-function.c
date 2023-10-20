#include "main.h"

/**
 * printCharacter - Prints a char
 * @types: List a of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: Width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printCharacter(va_list types, char b[],
	int f, int w, int p, int s)
{
	char c = va_arg(types, int);

	return (handlerWriteC(c, b, f, w, p, s));
}
/**
 * printString - Prints a string
 * @types: List a of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printString(va_list types, char b[],
	int f, int w, int p, int s)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (p >= 0 && p < length)
		length = p;

	if (w > length)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (w);
		}
	}

	return (write(1, str, length));
}
/**
 * printPercentage - Prints a percent sign
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printPercentage(va_list types, char b[],
	int f, int w, int p, int s)
{
	UNUSED(types);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	return (write(1, "%%", 1));
}

/**
 * printInteger - Print int
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printInteger(va_list types, char b[],
	int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convertSizeNumber(n, s);

	if (n == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writeNumbers(is_negative, i, b, f, w, p, s));
}

/**
 * printBinary - Prints an unsigned number
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width.
 * @p: Precision specification
 * @s: Size specifier
 * Return: Numbers of char printed.
 */
int printBinary(va_list types, char b[],
	int f, int w, int p, int s)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
