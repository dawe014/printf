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
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handlePrint(const char *fmt, int *i,
va_list l, char b[], int f, int w, int p, int s);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int printCharacter(va_list types, char b[],
	int f, int w, int p, int s);
int printString(va_list types, char b[],
	int f, int w, int p, int s);
int printPercentage(va_list types, char b[],
	int f, int w, int p, int s);

/* Functions to print numbers */
int printInteger(va_list types, char b[],
	int f, int w, int p, int s);
int printBinary(va_list types, char b[],
	int f, int w, int p, int s);
int printUnsigned(va_list types, char b[],
	int f, int w, int p, int s);
int printOctal(va_list types, char b[],
	int f, int w, int p, int s);
int printHexaDecimal(va_list types, char b[],
	int f, int w, int p, int s);
int printHexaUpper(va_list types, char b[],
	int f, int w, int p, int s);

int printHexa(va_list types, char m[],
char b[], int f, char flag_ch, int w, int p, int s);

/* Function to print non printable characters */
int printNonPrintable(va_list types, char b[],
	int f, int w, int p, int s);

/* Funcion to print memory address */
int printPointer(va_list types, char b[],
	int f, int w, int p, int s);

/* Funciotns to handle other specifiers */
int getFlags(const char *f, int *i);
int getWidth(const char *f, int *i, va_list l);
int getPrecision(const char *f, int *i, va_list l);
int getSize(const char *f, int *i);

/*Function to print string in reverse*/
int printReverse(va_list types, char b[],
	int f, int w, int p, int s);

/*Function to print a string in rot 13*/
int printRotstring(va_list types, char b[],
	int f, int w, int p, int s);

/* width handler */
int handlerWriteC(char c, char b[],
	int f, int w, int p, int s);
int writeNumbers(int is_positive, int ind, char b[],
	int f, int w, int p, int s);
int writeNum(int ind, char bff[], int f, int w, int p,
	int length, char padd, char extra_c);
int writePointer(char b[], int ind, int length,
	int w, int f, char padd, char extra_c, int padd_start);

int writeUnsigned(int is_negative, int ind,
char b[],
	int f, int w, int p, int s);

/****************** UTILS ******************/
int isPrintable(char);
int appendHexaCode(char, char[], int);
int isDigit(char);

long int convertSizeNumber(long int num, int s);
long int convertSizeUnsigned(unsigned long int num, int s);

#endif
