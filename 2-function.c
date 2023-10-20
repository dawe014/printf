#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * printPointer - Prints the value of a pointer variable
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed.
 */
int printMemoryAddress(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
char extraChar = 0, paddingChar = ' ';
int index = BUFF_SIZE - 2, length = 2, paddingStart = 1;
unsigned long numAddresses;
char mapTo[] = "0123456789abcdef";
void *addresses = va_arg(arguments, void *);

UNUSED(outputWidth);
UNUSED(sizeSpecifier);

if (addresses == NULL)
return (write(1, "(nil)", 5));

outputBuffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

numAddresses = (unsigned long)addresses;

while (numAddresses > 0)
{
outputBuffer[index--] = mapTo[numAddresses % 16];
numAddresses /= 16;
length++;
}

if ((activeFlags & F_ZERO) && !(activeFlags & F_MINUS))
paddingChar = '0';

index++;

return (writeMemoryAddress(outputBuffer, index, length, outputWidth,
activeFlags, paddingChar, extraChar, paddingStart));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * printNonPrintable - Prints ASCII codes in hexadecimal of non-printable
 * characters
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed.
 */
int printNonPrintableCharacters(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
int i = 0, offset = 0;
char *str = va_arg(arguments, char *);

UNUSED(activeFlags);
UNUSED(outputWidth);
UNUSED(precision);
UNUSED(sizeSpecifier);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (isCharacterPrintable(str[i]))
outputBuffer[i + offset] = str[i];
else
offset += appendHexadecimalCode(str[i], outputBuffer, i + offset);

i++;
}

outputBuffer[i + offset] = '\0';

return (write(1, outputBuffer, i + offset));
}

/**
 * printReversedString - Prints a reverse string.
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed.
 */

int printReversedString(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
char *string;
int i, count = 0;

UNUSED(outputBuffer);
UNUSED(activeFlags);
UNUSED(outputWidth);
UNUSED(sizeSpecifier);

string = va_arg(arguments, char *);

if (string == NULL)
{
UNUSED(precision);
string = ")Null(";
}

for (i = 0; string[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char x = string[i];
write(1, &x, 1);
count++;
}

return (count);
}

/**
 * printRot13String - Print a string in ROT13.
 * @arguments: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Calculates active flags
 * @outputWidth: Width
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed.
 */
int printRot13String(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier)
{
char x;
char *string;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

UNUSED(outputBuffer);
UNUSED(activeFlags);
UNUSED(outputWidth);
UNUSED(precision);
UNUSED(sizeSpecifier);

string = va_arg(arguments, char *);

if (string == NULL)
string = "(AHYY)";

for (i = 0; string[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == string[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = string[i];
write(1, &x, 1);
count++;
}
}

return (count);
}
