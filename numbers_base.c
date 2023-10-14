#include "main.h"

/**
 * print_hex_low - prints a number in hexadecimal base, in lowercase
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct flags that determinesif
 * a flag is passed to _printf
 *
 * Return: the number of char printed
 */
int print_hex_low(va_list list, print_f *flags)
{
	unsigned int n = va_arg(list, unsigned int);
	char *ch = convertToBaseString(n, 16, 1);
	int i = 0;

	if (flags->h == 1 && ch[0] != '0')
		i += _puts("0x");
	i += _puts(ch);
	return (i);
}

/**
 * print_hex_up - prints a number in hexadecimal base, in uppercase
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct that determines if a flag is passed to _printf
 * Return: the number of char printed
 */
int print_hex_up(va_list list, print_f *flags)
{
	unsigned int n = va_arg(list, unsigned int);
	char *ch = convertToBaseString(n, 16, 0);
	int i = 0;

	if (flags->h == 1 && ch[0] != '0')
		i += _puts("0X");

	i += _puts(ch);
	return (i);
}

/**
 * print_bin - prints a number in binary form
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct that determines if a flag is passed to _printf
 *
 * Return: the number of char printed
 */
int print_bin(va_list list, print_f *flags)
{
	unsigned int n = va_arg(list, unsigned int);
	char *ch = convertToBaseString(n, 2, 0);

	(void)flags;
	return (_puts(ch));
}

/**
 * print_octal_form - prints a number in octal form
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct that determines if a flag is passed to _printf
 *
 * Return: the number of char printed
 */
int print_octal_form(va_list list, print_f *flags)
{
	unsigned int n = va_arg(list, unsigned int);
	char *ch = convertToBaseString(n, 8, 0);
	int i = 0;

	if (flags->h == 1 && ch[0] != '0')
		i += _putchar('0');
	i += _puts(ch);
	return (i);
}
