#include "main.h"

/**
 * is_digit - Verifies if a char is a digit or digits
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, or 0 otherwise
 */
int is_digit(char c)
{
	 if (c >= '0' && c <= '9')
		 return (1);

	  return (0);
}

/**
 * append_hexadecimal_code - Append ascii in hexadecimal code to the buffer
 * @buffer: Array of chars.
 * @i: Index at which to start the appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexadecimal_code(char ascii_code, char buffer[], int i)
{
	char mapped_to[] = "0123456789ABCDEF";
	/* The hexadecimal format codes are and is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = mapped_to[ascii_code / 16];
	buffer[i] = mapped_to[ascii_code % 16];

	return (3);
}

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char that to check or evaluated.
 *
 * Return: 1 if c is printable,or 0 otherwise
 */
int is_printable(char c)
{
	 if (c >= 32 && c < 127)
		 return (1);

	 return (0);
}

/**
 * convert_size_unsigned_int - Casts a or the number to the specified size or sizes
 * @size: Number indicating the type to be casted
 * @num: Number to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsigned_int(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);

	else if (size == SIZE_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * convert_size_numbers - Casts a number to the specified size or sizes
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_numbers(long int num, int size)
{
	if (size == SIZE_LONG)
		 return (num);

	 else if (size == SIZE_SHORT)
		  return ((short)num);

	  return ((int)num);
}
