#include "main.h"

/** PRINT A STRING ***/
/**
 * print_strings - Prints a string
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_strings(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = var_arg(types, char *);

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/** PRINT CHAR ***/

/**
 * print_char - Prints a char or chars
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = var_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******* PRINT PERCENT SIGN *********/
/**
 * print_percent - Prints a percent sign
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);

	return (write(1, "%%", 1));
}

/********* PRINT INT *******/
/**
 * print_int - Prints integer number or numbers
 * @types: Lists of arguments
 * @flags:  Calculates the active flags
 * @width: get width.
 * @precision: Precision specifications
 * @size: Size specifier
 * @buffer: Buffer array to handle print
 * Return: Number of chars that are printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = var_arg(types, long int);
	unsigned long int num;

	n = convert_size_numbers(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/********* PRINT BINARY *********/
/**
 * print_binary - Prints an unsigned binary number or numbers
 * @types: Lists of arguments
 * @width: get width.
 * @precision: Precision specifications
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int counter;

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	n = var_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, counter = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}

