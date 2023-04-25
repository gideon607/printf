#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/* Miscellous */
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* SIZE(S) */
#define SIZE_SHORT 1
#define SIZE_LONG 2

/* FLAG(S) */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

int _printf(const char *format, ...);
int handle_prints(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
void print_buffers(char buffer[], int *buff_ind);

/*** FUNCTIONS ***/

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexaAz(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Functions to print chars and strings */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_strings(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printables(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory-address */
int print_pointers(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_width(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print strings in reverse */
int print_inreverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_rot13strings(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handlers */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

int write_unsignd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/**
 * struct fmt - Struct operation (format) and the function
 *
 * @fmt: The format.
 * @fn: The function of the fmt involved.
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
 * @fm_t: The function that is associated.
 */
typedef struct fmt fmt_t;

/** UTILS ***/
int is_digit(char);
int is_printable(char);
int append_hexadecimal_code(char, char[], int);
long int convert_size_unsigned(unsigned long int num, int size);
long int convert_size_numbers(long int num, int size);

#endif /* MAIN_H */

