#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
/**
 * struct PrintFlags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @p: flag for the '+' character
 * @s: flag for the ' ' character
 * @h: flag for the '#' character
 */
typedef struct PrintFlags
{
	int p;
	int s;
	int h;
} print_f;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct PrintFunctionDescriptor
{
	char c;
	int (*f)(va_list ap, print_f *f);
} pfd;

int _printf(const char *format, ...);
int _putchar(char ch);
int _puts(char *ptr);
int print_str(va_list list, print_f *flags);
int print_chacter(va_list list, print_f *flags);
int print_per(va_list list, print_f *flags);
int display_int(va_list list, print_f *flags);
int disp_unsigned_int(va_list list, print_f *flags);
int disp_num_digit(int num);
void disp_num(int num);
int parse_flag(char ch, print_f *flags);
int print_octal_form(va_list list, print_f *flags);
int print_bin(va_list list, print_f *flags);
int print_hex_up(va_list list, print_f *flags);
int print_hex_low(va_list list, print_f *flags);
int disp_nonprintable_char(va_list list, print_f *flags);
int disp_str_rev(va_list list, print_f *flags);
int disp_str_rot13(va_list list, print_f *flags);
int disp_address(va_list list, print_f *flags);
char *convertToBaseString(unsigned long int n, int b, int lcase);
int (*PrintFunction(char s))(va_list, print_f *);
#endif
