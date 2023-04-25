#include "main.h"

/******** PRINT NON PRINTABLES ******/
/**
 * print_non_printables - Prints ascii codes in hexa of non printable chars
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printables(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);


	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexadecimal_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**** PRINT POINTER VALUE ****/
/**
 * print_pointers - Prints the value or values of a pointer variable
 * @types: List of arguments
 * @precision: Precision specifications
 * @size: Size specifier
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * Return: Number of chars printed.
 */
int print_pointers(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char mapped_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);


	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = mapped_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padd = '0';

	if (flags & FLAG_PLUS)
		extra_c = '+', length++;

	else if (flags & FLAG_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/***** PRINT REVERSE ****/
/**
 * print_inreverse - Prints reverse strings.
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_inreverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}

	return (count);
}

/***** PRINT A STRING IN ROT13 ****/
/**
 * print_rot13strings - Print a string in rot13.
 * @types: Lists of arguments
 * @size: Size specifier
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * Return: Numbers of chars printed
 */
int print_rot13strings(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}

		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}

