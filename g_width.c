#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	 int curr_ipre;
	 int width = 0;

	 for (curr_ipre = *i + 1; format[curr_ipre] != '\0'; curr_ipre++)
	 {
		 if (is_digit(format[curr_ipre]))
		 {
			  width *= 10;
			  width += format[curr_ipre] - '0';
		 }

		 else if (format[curr_ipre] == '*')
		 {
			 curr_ipre++;
			 width = va_arg(list, int);
			 break;
		 }

		 else
			 break;
	 }

	 *i = curr_ipre - 1;

	 return (width);
}
