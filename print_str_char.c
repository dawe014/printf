#include "main.h"

/**
 * print_str - loops through a string and prints every character
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct flags that determines if
 * a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_str(va_list list, print_f *flags)
{
	char *str = va_arg(list, char *);

	(void)flags;

	if (!str)
		str = "(null)";
	return (_puts(str));
}

/**
 * print_chacter - prints a character
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct flags that determines if
 * a flag is passed to _printf
 *
 * Return: number of char printed
 */
int print_chacter(va_list list, print_f *flags)
{
	(void)flags;
	_putchar(va_arg(list, int));
	return (1);
}
/**
 * print_per - prints a percent char
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_per(va_list list, print_f *flags)
{
	(void)list;
	(void)flags;
	return (_putchar('%'));
}
