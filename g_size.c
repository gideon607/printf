#include "main.h"

/**
 * get_size - Calculates the size to cast the arguments
 * @i: List of arguments to be printed
 * @format: Formatted string in which to print the arguments
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	 int curr_ipre = *i + 1;
	 int size = 0;

	 if (format[curr_ipre] == 'l')
		 size = SIZE_LONG;

	 else if (format[curr_ipre] == 'h')
		 size = SIZE_SHORT;

	  if (size == 0)
		  *i = curr_ipre - 1;

	  else
		   *i = curr_ipre;

	   return (size);
}