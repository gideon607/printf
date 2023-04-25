#include "main.h"

/**** PRINT UNSIGNED NUMBER *****/
/**
 * print_unsigned - Prints an unsigned number or numbers
 * @types: List of arguments
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifier
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}


/***** PRINT UNSIGNED NUMBER IN HEXADECIMAL *****/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexaAz(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/****** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ******/
/**
 * print_hexadecimal_upper - Prints an unsigned number in upper hexadecimal like notation
 * @types: List of arguments
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @buffer: Buffer array to handle print
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexaAz(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/***** PRINTS HEX NUM IN LOWER OR UPPER *****/
/**
 * print_hexaAz - Prints a hexadecimal number(s) in lower or upper
 * @types: Lists of arguments
 * @size: Size specifiers
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifications
 * Return: Number of chars thats printed
 */
int print_hexaAz(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FLAG_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/***** PRINT UNSIGNED NUMBER IN OCTAL  ******/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned_int(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLAG_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

