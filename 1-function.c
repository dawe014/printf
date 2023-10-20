#include "main.h"

/**
 * printUnsigned - Prints an unsigned number
 * @types: List a of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int printUnsigned (va_list types, char b[],
	int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convertSizeUnsigned(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writeUnsigned(0, i, b, f, w, p, s));
}

/**
 * printOctal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printOctal(va_list types, char b[],
int f, int w, int p, int s)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convertSizeUnsigned(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		b[i--] = '0';

	i++;

	return (writeUnsigned(0, i, b, f, w, p, s));
}

/**
 * printHexaDecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printHexaDecimal(va_list types, char b[],
	int f, int w, int p, int s)
{
	return (printHexa(types, "0123456789abcdef", b,
		f, 'x', w, p, s));
}

/**
 * printHexaUpper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int printHexaUpper(va_list types, char b[],
	int f, int w, int p, int s)
{
	return (printHexa(types, "0123456789ABCDEF", b,
		f, 'X', w, p, s));
}

/**
 * printHexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @m: Array of values to map the number to
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: get width
 * @p: Precision specification
 *
 * @s: Size specification
 * Return: Number of chars printed
 */
int printHexa(va_list types, char m[], char b[],
	int f, char flag_ch, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convertSizeUnsigned(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = m[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		b[i--] = flag_ch;
		b[i--] = '0';
	}

	i++;

	return (writeUnsigned(0, i, b, f, w, p, s));
}
