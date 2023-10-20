#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * printUnsignedNumber - Prints an unsigned number
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed.
 */
int printUnsignedNumber(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(arguments, unsigned long int);

num = convertSizeSpecifiedUnsignedNumber(num, sizeSpecifier);

if (num == 0)
outputBuffer[i--] = '0';
outputBuffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
outputBuffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;
return (writeUnsignedNumber(0, i, outputBuffer, activeFlags, outputWidth,
precision, sizeSpecifier));
}

/**
 * printOctal - Prints an unsigned number in octal notation
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printOctal(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(arguments, unsigned long int);
unsigned long int initialNumber = num;

UNUSED(outputWidth);

num = convertSizeSpecifiedUnsignedNumber(num, sizeSpecifier);

if (num == 0)
outputBuffer[i--] = '0';

outputBuffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
outputBuffer[i--] = (num % 8) + '0';
num /= 8;
}
if (activeFlags & F_HASH && initialNumber != 0)
outputBuffer[i--] = '0';

i++;

return (writeUnsignedNumber(0, i, outputBuffer, activeFlags,
outputWidth, precision, sizeSpecifier));
}

/**
 * printHexadecimal - Prints an unsigned number in hexadecimal notation
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printHexadecimal(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
return (printHexadecimalFormatter(arguments, "0123456789abcdef", outputBuffer,
activeFlags, 'x', outputWidth, precision, sizeSpecifier));
}

/**
 * printHexadecimalUpper - Prints an unsigned number in upper
 * hexadecimal notation
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printHexadecimalUpper(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
return (printHexadecimalFormatter(arguments, "0123456789ABCDEF", outputBuffer,
activeFlags, 'X', outputWidth, precision, sizeSpecifier));
}

/**
 * printHexadecimalFormatter - Prints a hexadecimal number in lower or upper
 * @arguments: List of arguments
 * @mapTo: Array of values to map the number to
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @flagChar: Active flag character
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * @sizeSpecifier: Size specification
 * Return: Number of characters printed
 */
int printHexadecimalFormatter(va_list arguments, char mapTo[],
char outputBuffer[], int activeFlags, char flagChar,
int w, int precision, int sizeSpecifier)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(arguments, unsigned long int);
unsigned long int initialNumber = num;

UNUSED(w);

num = convertSizeSpecifiedUnsignedNumber(num, sizeSpecifier);

if (num == 0)
outputBuffer[i--] = '0';
outputBuffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
outputBuffer[i--] = mapTo[num % 16];
num /= 16;
}
if (activeFlags & F_HASH && initialNumber != 0)
{
outputBuffer[i--] = flagChar;
outputBuffer[i--] = '0';
}
i++;
return (writeUnsignedNumber(0, i, outputBuffer, activeFlags,
w, precision, sizeSpecifier));
}
