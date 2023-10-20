#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @currentIndex: Current index in the format string.
 * @argsList: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed or -1 if an unsupported format found.
 */
int handlePrintFormat(const char *fmt, int *currentIndex, va_list argsList,
char buffer[], int flags, int width, int precision, int size)
{
int i, unknownLen = 0, printedChars = -1;
fmt_t fmtTypes[] = {
{'c', printCharacter}, {'s', printString}, {'%', printPercentSign},
{'i', printInteger}, {'i', printInteger}, {'b', printBinary},
{'u', printUnsignedNumber}, {'o', printOctal}, {'x', printHexadecimal},
{'X', printHexadecimalUpper}, {'p', printMemoryAddress}, {'S', printNonPrintableCharacters},
{'r', printReversedString}, {'R', printRot13String}, {'\0', NULL}
};
for (i = 0; fmtTypes[i].format != '\0'; i++)
{
if (fmt[*currentIndex] == fmtTypes[i].format)
return (fmtTypes[i].printFunction(argsList, buffer, flags,
width, precision, size));
}

if (fmtTypes[i].format == '\0')
{
if (fmt[*currentIndex] == '\0')
return (-1);
unknownLen += write(1, "%%", 1);
if (fmt[*currentIndex - 1] == ' ')
unknownLen += write(1, " ", 1);
else if (width)
{
--(*currentIndex);
while (fmt[*currentIndex] != ' ' && fmt[*currentIndex] != '%')
--(*currentIndex);
if (fmt[*currentIndex] == ' ')
--(*currentIndex);
return (1);
}
unknownLen += write(1, &fmt[*currentIndex], 1);
return (unknownLen);
}
return (printedChars);
}
