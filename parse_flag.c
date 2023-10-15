#include "main.h"
/**
 * parse_flag - turns on flags if _printf finds
 * @ch: character that holds the flag specifier
 * @flags: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int parse_flag(char ch, print_f *flags)
{
int i = 0;
switch (ch)
{
case '+':
flags->p = 1;
i = 1;
break;
case ' ':
flags->s = 1;
i = 1;
break;
case '#':
flags->h = 1;
i = 1;
break;
}
return (i);
}
