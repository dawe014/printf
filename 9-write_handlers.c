#include "main.h"

/**
 * handleWriteCharacter - Prints a character
 * @character: Character to be printed.
 * @outputBuffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @outputWidth: get width.
 * @precision: precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int handleWriteCharacter(char character, char outputBuffer[], int flags,
		int outputWidth, int precision, int size)
{
	/* Character is stored at left, and padding is at the buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';
	outputBuffer[i++] = character;
	outputBuffer[i] = '\0';
	if (outputWidth > 1)
	{
		outputBuffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < outputWidth - 1; i++)
			outputBuffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &outputBuffer[0], 1) +
					write(1, &outputBuffer[BUFF_SIZE - i - 1], outputWidth - 1));
		else
			return (write(1, &outputBuffer[BUFF_SIZE - i - 1], outputWidth - 1)
					+ write(1, &outputBuffer[0], 1));
	}
	return (write(1, &outputBuffer[0], 1));
}

/**
 * write_number - Prints a number
 * @isPositive: Flag indicating if the number is negative.
 * @index: Index of the number in the buffer.
 * @outputBuffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @outputWidth: get width.
 * @precision: precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int writeNumber(int isPositive, int index, char outputBuffer[],
int flags, int outputWidth, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (isPositive)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (writeFormattedNumber(index, outputBuffer, flags, outputWidth,
				precision, length, padd, extra_ch));
}

/**
 * writeFormattedNumber - Write a number using a buffer
 * @index: Index at which the number starts in the buffer.
 * @buffer: Buffer.
 * @flags: Flags.
 * @outputWidth: Width.
 * @precision: Precision specifier.
 * @length: Number length.
 * @paddingChar: Padding character.
 * @extraChar: Extra character.
 *
 * Return: Number of printed characters.
 */
int writeFormattedNumber(int index, char buffer[], int flags, int outputWidth,
		int precision, int length, char paddingChar, char extraChar)
{
	int i;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0'
&& outputWidth == 0)
		return (0); /* printf(".0d", 0) - no character is printed */
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
	{
		buffer[index] = paddingChar = ' '; /* width is displayed with padding ' ' */
	}
	if (precision > 0 && precision < length)
		paddingChar = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if (extraChar != 0)
		length++;
	if (outputWidth > length)
	{
		for (i = 1; i < outputWidth - length + 1; i++)
			buffer[i] = paddingChar;
		buffer[i] = '\0';
		if (flags & F_MINUS && paddingChar == ' ')
		{
			if (extraChar)
				buffer[--index] = extraChar;
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[BUFF_SIZE - i - 1], outputWidth - 1) +
write(1, &buffer[0], 1));
		}
	}
	return (write(1, &buffer[0], 1));
}
/**
 * writeUnsignedNumber - Writes an unsigned number
 * @isNegative: Flag indicating if the number is negative.
 * @index: Index of the number in the buffer.
 * @outputBuffer: Buffer array.
 * @flags: Flags specifiers.
 * @outputWidth: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of written characters.
 */
int writeUnsignedNumber(int isNegative, int index, char outputBuffer[],
		int flags, int outputWidth, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position i */
	int length = BUFF_SIZE - index - 1, i = 0;
	char padd = ' ';

	UNUSED(isNegative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && outputBuffer[index] == '0')
		return (0); /* printf(".0d", 0) - no character is printed */

	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		outputBuffer[--index] = '0';
		length++;
	}
	if (flags & F_ZERO && !(flags & F_MINUS))
		padd = '0';
	if (outputWidth > length)
	{
		for (i = 0; i < outputWidth - length; i++)
			outputBuffer[i] = padd;
		outputBuffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &outputBuffer[index], length) +
write(1, &outputBuffer[0], i));
		}
		else
		{
			return (write(1, &outputBuffer[0], i) +
write(1, &outputBuffer[index], length));
		}
	}
	return (write(1, &outputBuffer[index], length));
}

/**
 * writeMemoryAddress - Write a memory address
 * @outputBuffer: Arrays of characters.
 * @index: Index at which the number starts in the buffer.
 * @length: Length of the number.
 * @outputWidth: Width specifier.
 * @flags: Flags specifier.
 * @paddingChar: Char representing the padding.
 * @extraChar: Char representing extra character.
 * @padd_start: Index at which padding should start.
 *
 * Return: Number of written characters.
 */
int writeMemoryAddress(char outputBuffer[], int index, int length,
		int outputWidth, int flags, char paddingChar, char extraChar, int padd_start)
{
	int i;

	if (outputWidth > length)
	{
		for (i = 3; i < outputWidth - length + 3; i++)
			outputBuffer[i] = paddingChar;
		outputBuffer[i] = '\0';
		if (flags & F_MINUS && paddingChar == ' ')
		{
			outputBuffer[--index] = 'x';
			outputBuffer[--index] = '0';
			if (extraChar)
				outputBuffer[--index] = extraChar;
			return (write(1, &outputBuffer[index], length) +
					write(1, &outputBuffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && paddingChar == ' ')
		{
			outputBuffer[--index] = 'x';
			outputBuffer[--index] = '0';
			if (extraChar)
				outputBuffer[--index] = extraChar;
			return (write(1, &outputBuffer[3], i - 3) + write(1,
						&outputBuffer[index], length));
		}
		else if (!(flags & F_MINUS) && paddingChar == '0')
		{
			if (extraChar)
				outputBuffer[--padd_start] = extraChar;
			outputBuffer[1] = '0';
			outputBuffer[2] = 'x';
			return (write(1, &outputBuffer[padd_start], i - padd_start) +
					write(1, &outputBuffer[index], length - (1 - padd_start) - 2));
		}
	}
	outputBuffer[--index] = 'x';
	outputBuffer[--index] = '0';
	if (extraChar)
		outputBuffer[--index] = extraChar;
	return (write(1, &outputBuffer[index], BUFF_SIZE - index - 1));
}
