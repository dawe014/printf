#include "main.h"

/**
 * convertToBaseString - converts number and base into string
 * @n: input number
 * @b: input base
 * @lcase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convertToBaseString(unsigned long int n, int b, int lcase)
{
	static char *r;
	static char buffer[50];
	char *str;

	r = (lcase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';
	do {
		*--str = r[n % b];
		n /= b;
	} while (n != 0);

	return (str);
}
