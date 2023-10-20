#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * printCharacter - Prints a character
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printCharacter(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
char character = va_arg(arguments, int);
return (handleWriteCharacter(character, outputBuffer, activeFlags,
outputWidth, precision, sizeSpecifier));
}



/**
 * printString - Prints a string
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printString(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier)
{
int length = 0, i;
char *str = va_arg(arguments, char *);

UNUSED(outputBuffer);
UNUSED(activeFlags);
UNUSED(outputWidth);
UNUSED(precision);
UNUSED(sizeSpecifier);

if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;

if (outputWidth > length)
{
if (activeFlags & F_MINUS)
{
write(1, &str[0], length);
for (i = outputWidth - length; i > 0; i--)
write(1, " ", 1);
return (outputWidth);
}
else
{
for (i = outputWidth - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (outputWidth);
}
}
return (write(1, str, length));
}

/**
 * printPercentSign - Prints a percent sign
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printPercentSign(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier)
{
UNUSED(arguments);
UNUSED(outputBuffer);
UNUSED(activeFlags);
UNUSED(outputWidth);
UNUSED(precision);
UNUSED(sizeSpecifier);
return (write(1, "%%", 1));
}

/**
 * printInteger - Print an integer
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printInteger(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier)
{
int i = BUFF_SIZE - 2;
int isNegative = 0;
long int n = va_arg(arguments, long int);
unsigned long int num;

n = convertSizeSpecifiedNumber(n, sizeSpecifier);

if (n == 0)
outputBuffer[i--] = '0';
outputBuffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
isNegative = 1;
}
while (num > 0)
{
outputBuffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (writeNumber(isNegative, i, outputBuffer, activeFlags,
outputWidth, precision, sizeSpecifier));
}

/**
 * printBinary - Prints an unsigned number
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int printBinary(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;

UNUSED(outputBuffer);
UNUSED(activeFlags);
UNUSED(outputWidth);
UNUSED(precision);
UNUSED(sizeSpecifier);

n = va_arg(arguments, unsigned int);
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
