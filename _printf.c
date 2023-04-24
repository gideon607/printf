#include "main.h"

void print_buffers(char buffer[], int *buff_ind);

/**
 * print_buffers - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: Index at the point to add next char, i.e the length.
 */
void print_buffers(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed char.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffers(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_char++;
		}
		else
		{
			print_buffers(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_char += printed;
		}
	}

	print_buffers(buffer, &buff_ind);

	va_end(list);

	return (printed_char);
}

