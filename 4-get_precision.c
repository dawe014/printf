#include "main.h"

/**
 * calculatePrecision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @cIndex: Current index in the format string
 * @argsList: List of arguments
 *
 * Return: Precision.
 */
int calculatePrecision(const char *format, int *cIndex, va_list argsList)
{
int currIndex = *cIndex + 1;
int precision = -1;

if (format[currIndex] != '.')
return (precision);
precision = 0;

for (currIndex += 1; format[currIndex] != '\0'; currIndex++)
{
if (isDigitCharacter(format[currIndex]))
{
precision *= 10;
precision += format[currIndex] - '0';
}
else if (format[currIndex] == '*')
{
currIndex++;
precision = va_arg(argsList, int);
break;
}
else
{
break;
}
}

*cIndex = currIndex - 1;

return (precision);
}
