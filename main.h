#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct PrintFormat - Structure to represent a print format
 *
 * @format: The format specifier.
 * @printFunction: The associated printing function.
 */
struct PrintFormat
{
	char format;
	int (*printFunction)(va_list, char[], int, int, int, int);
};

/**
 * typedef fmt_t - Typedef for PrintFormat structure
 *
 * @format: The format specifier.
 * @printFunction: The associated printing function.
 */
typedef struct PrintFormat fmt_t;

int _printf(const char *format, ...);
int handlePrintFormat(const char *fmt, int *currentIndex, va_list argsList,
char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int printCharacter(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int printString(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int printPercentSign(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);

/* Functions to print numbers */
int printInteger(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int printBinary(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int printUnsignedNumber(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier);
int printOctal(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int printHexadecimal(va_list argumentList, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int printHexadecimalUpper(va_list argumentList, char outputBuffer[],
int flags, int outputWidth, int precision, int size);

int printHexadecimalFormatter(va_list argumentList, char characterMap[],
char outputBuffer[], int flags, char flagChar, int w, int precision, int size);

/* Function to print non-printable characters */
int printNonPrintableCharacters(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier);

/* Function to print memory addresses */
int printMemoryAddress(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier);

/* Functions to handle other specifiers */
int calculateActiveFlags(const char *format, int *currentIndex);
int calculateWidth(const char *format, int *currentIndex, va_list argsList);
int calculatePrecision(const char *format, int *cIndex, va_list argsList);

int calculateSize(const char *format, int *currentIndex);

/* Function to print a string in reverse */
int printReversedString(va_list arguments, char outputBuffer[],
int activeFlags, int outputWidth, int precision, int sizeSpecifier);

/* Function to print a string in ROT13 encoding */
int printRot13String(va_list arguments, char outputBuffer[], int activeFlags,
int outputWidth, int precision, int sizeSpecifier);

/* Width handler */
int handleWriteCharacter(char character, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int writeNumber(int isPositive, int index, char outputBuffer[], int flags,
int outputWidth, int precision, int size);
int writeFormattedNumber(int index, char buffer[], int flags, int outputWidth,
int precision, int length, char paddingChar, char extraChar);
int writeMemoryAddress(char outputBuffer[], int index, int length,
int outputWidth, int flags, char paddingChar, char extraChar, int padd_start);

int writeUnsignedNumber(int isNegative, int index, char outputBuffer[],
int flags, int outputWidth, int precision, int size);

/****************** UTILS ******************/
int isCharacterPrintable(char character);
int appendHexadecimalCode(char input, char output[], int index);
int isDigitCharacter(char character);

long int convertSizeSpecifiedNumber(long int number, int size);
long int convertSizeSpecifiedUnsignedNumber(unsigned int number, int size);

#endif
