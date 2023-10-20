#include "main.h"

/**
 * isCharacterPrintable - Evaluates if a character is printable
 * @character: Character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int isCharacterPrintable(char character)
{
if (character >= 32 && character < 127)
return (1);
return (0);
}

/**
 * appendHexadecimalCode - Append ASCII in hexadecimal code to the buffer
 * @output: Array of characters.
 * @index: Index at which to start appending.
 * @input: ASCII code.
 *
 * Return: Always 3.
 */
int appendHexadecimalCode(char input, char output[], int index)
{
char map_to[] = "0123456789ABCDEF";
/* The hexadecimal format code is always 2 digits long */
if (input < 0)
input *= -1;

output[index++] = '\\';
output[index++] = 'x';

output[index++] = map_to[input / 16];
output[index] = map_to[input % 16];

return (3);
}

/**
 * isDigitCharacter - Verifies if a character is a digit
 * @c: Character to be evaluated.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int isDigitCharacter(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convertSizeSpecifiedNumber - Casts a number to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num.
 */
long int convertSizeSpecifiedNumber(long int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((short)number);

return ((int)number);
}

/**
 * convertSizeSpecifiedUnsignedNumber - Casts an unsigned number
 * to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num.
 */
long int convertSizeSpecifiedUnsignedNumber(unsigned int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((unsigned short)number);

return ((unsigned int)number);
}
