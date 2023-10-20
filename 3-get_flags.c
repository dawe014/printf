#include "main.h"

/**
 * calculateActiveFlags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @currentIndex: Current index in the format string
 * Return: Active flags
 */
int calculateActiveFlags(const char *format, int *currentIndex)
{
int j, currIndex;
int activeFlags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (currIndex = *currentIndex + 1; format[currIndex] != '\0'; currIndex++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
{
if (format[currIndex] == FLAGS_CH[j])
{
activeFlags |= FLAGS_ARR[j];
break;
}
}

if (FLAGS_CH[j] == 0)
break;
}

*currentIndex = currIndex - 1;

return (activeFlags);
}
