#include "main.h"

/**
 * get_precision - Calculates the overall precision for prints or the printing
 * @format: Formatted string in which to print the arguments
 * @list: list of arguments.
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	 int curr_ipre = *i + 1;
	 int precision = -1;

	 if (format[curr_ipre] != '.')
		 return (precision);

	 precision = 0;

	 for (curr_ipre += 1; format[curr_ipre] != '\0'; curr_ipre++)
	 {
		 if (is_digit(format[curr_ipre]))
		 {
			 precision *= 10;
			 precision += format[curr_ipre] - '0';
		 }

		 else if (format[curr_ipre] == '*')
		 {
			  curr_ipre++;
			  precision = var_arg(list, int);
			  break;
		 }

		  else
			  break;
	 }

	 *i = curr_ipre - 1;

	  return (precision);
}

