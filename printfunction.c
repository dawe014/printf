#include "main.h"

/**
 * PrintFunction - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 *
 * Return: a pointer to the matching printing function
 */
int (*PrintFunction(char s))(va_list, print_f *)
{
	pfd func_arr[] = {
		{'i', display_int},
		{'s', print_str},
		{'c', print_chacter},
		{'d', display_int},
		{'u', disp_unsigned_int},
		{'x', print_hex_low},
		{'X', print_hex_up},
		{'b', print_bin},
		{'o', print_octal_form},
		{'R', disp_str_rot13},
		{'r', disp_str_rev},
		{'S', disp_nonprintable_char},
		{'p', disp_address},
		{'%', print_per}
		};
	int fl = 14;

	register int i;

	for (i = 0; i < fl; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
