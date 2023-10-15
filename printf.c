#include "main.h"
/**
 * _printf - printf function
 * @format: const char pointer
 * Return: b_len
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, print_f *);
	const char *ptr;
	va_list args;
	print_f flags = {0, 0, 0};

	register int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (parse_flag(*ptr, &flags))
				ptr++;
			pfunc = PrintFunction(*ptr);
			count += (pfunc)
				? pfunc(args, &flags)
				: _printf("%%%c", *ptr);
		} else
			count += _putchar(*ptr);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
