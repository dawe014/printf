#include "main.h"

/**
 * isPrintable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int isPrintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appendHexaCode - Append ascci in hexadecimal code to buffer
 * @b: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int appendHexaCode(char ascii_code, char b[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	b[i++] = '\\';
	b[i++] = 'x';

	b[i++] = map_to[ascii_code / 16];
	b[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * isDigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convertSizeNumber - Casts a number to the specified size
 * @num: Number to be casted.
 * @s: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convertSizeNumber(long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convertSizeUnsigned - Casts a number to the specified size
 * @num: Number to be casted
 * @s: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convertSizeUnsigned (unsigned long int num, int s)
{
	if (s == S_LONG)
		return (num);
	else if (s == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
