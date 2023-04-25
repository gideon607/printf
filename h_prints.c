#include "main.h"
/**
 * handle_prints - Prints an argument focused on its types
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of the arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: get width.
 * @precision: Precision specifications.
 * @size: Size specifier.
 * @ind: ind.
 * Return: 1 or 2;
 */
int handle_prints(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_leng = 0, printed_char = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_strings}, {'%', print_percent},
		{'i', print_int}, {'b', print_binary}, {'d', print_int},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexadecimal_upper}, {'S', print_non_printables}, {'p', print_pointers},
		{'r', print_inreverse}, {'R', print_rot13strings}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_leng += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_leng += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_leng += write(1, &fmt[*ind], 1);
		return (unknow_leng);
	}

	return (printed_char);
}
