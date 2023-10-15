#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 */
int _putchar(char ch)
{
	static char buffer[1024];
	static int i;

	if (ch == -1 || i >= 1024)
	{
		write(1, &buffer, i);
		i = 0;
	}
	if (ch != -1)
	{
		buffer[i] = ch;
		i++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @ptr: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *ptr)
{
	register int count;

	for (count = 0; ptr[count] != '\0'; count++)
		_putchar(ptr[count]);
	return (count);
}
