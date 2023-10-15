#include "main.h"

/**
 * disp_address - prints address of input in hexa format
 * @list: va_list arguments from _printf
 * @flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int disp_address(va_list list, print_f *flags)
{
	char *ptr;
	unsigned long int u = va_arg(list, unsigned long int);

	register int i = 0;

	(void)flags;

	if (!u)
		return (_puts("(nil)"));
	ptr = convertToBaseString(u, 16, 1);
	i += _puts("0x");
	i += _puts(ptr);
	return (i);
}
