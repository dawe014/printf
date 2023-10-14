#include "main.h"

/**
 * display_int - prints an integer
 * @list: va_list of arguments from _printf
 * @flags: pointer to the struct flags determining if
 * a flag is passed to _printf
 * Return: number of char printed
 */
int display_int(va_list list, print_f *flags)
{
	int num = va_arg(list, int);
	int res = disp_num_digit(num);

	if (flags->s == 1 && flags->p == 0 && num >= 0)
		res += _putchar(' ');
	if (flags->p == 1 && num >= 0)
		res += _putchar('+');
	if (num <= 0)
		res++;
	disp_num(num);
	return (res);
}

/**
 * disp_unsigned_int - prints an unsigned integer
 * @list: va_list of arguments from _printf
 * @flags: pointer to the struct flags determining if
 * a flag is passed to _printf
 * Return: number of char printed
 */
int disp_unsigned_int(va_list list, print_f *flags)
{
	unsigned int unsign = va_arg(list, unsigned int);
	char *ptr = convertToBaseString(unsign, 10, 0);

	(void)flags;
	return (_puts(ptr));
}

/**
 * disp_num_digit - returns the number of digits in an integer
 * for _printf
 * @num: integer to evaluate
 * Return: number of digits
 */
int disp_num_digit(int num)
{
	unsigned int i = 0;
	unsigned int n;

	if (num < 0)
		n = num * -1;
	else
		n = num;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}


/**
 * disp_num - helper function that loops through an integer
 * and prints all its digits
 * @num: integer to be printed
 */
void disp_num(int num)
{
	unsigned int n;

	if (num < 0)
	{
		_putchar('-');
		n = -num;
	}
	else
		n = num;

	if (n / 10)
		disp_num(n / 10);
	_putchar((n % 10) + '0');
}
