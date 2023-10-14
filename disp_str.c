#include "main.h"

/**
 * disp_nonprintable_char - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code value
 * in hexadecimal (upper case - always 2 characters)
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int disp_nonprintable_char(va_list list, print_f *flags)
{
	int n, i = 0;
	char *ptr;
	char *str = va_arg(list, char *);

	(void)flags;
	if (!str)
		return (_puts("(null)"));

	for (n = 0; str[n]; n++)
	{
		if (str[n] > 0 && (str[n] < 32 || str[n] >= 127))
		{
			_puts("\\x");
			i += 2;
			ptr = convertToBaseString(str[n], 16, 0);
			if (!ptr[1])
				i += _putchar('0');
			i += _puts(ptr);
		}
		else
			i += _putchar(str[n]);
	}
	return (i);
}

/**
 * disp_str_rev - prints a string in reverse
 * @list: argument from _printf
 * @flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int disp_str_rev(va_list list, print_f *flags)
{
	int count = 0, n;
	char *str = va_arg(list, char *);

	(void)flags;
	if (!str)
		str = "(null)";

	while (str[count])
		count++;

	for (n = count - 1; n >= 0; n--)
		_putchar(str[n]);

	return (count);
}

/**
 * disp_str_rot13 - prints a string using rot13
 * @list: list of arguments from _printf
 * @flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int disp_str_rot13(va_list list, print_f *flags)
{
	int i, j;
	char r13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char R13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(list, char *);

	(void)flags;
	for (j = 0; str[j]; j++)
	{
		if (str[j] < 'A' || (str[j] > 'Z' && str[j] < 'a') || str[j] > 'z')
			_putchar(str[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (str[j] == r13[i])
					_putchar(R13[i]);
			}
		}
	}

	return (j);
}
