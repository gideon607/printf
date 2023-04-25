#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @i: taken as a parameter.
 * @format: Formatted string in which to print the arguments
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_ipre;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

	for (curr_ipre = *i + 1; format[curr_ipre] != '\0'; curr_ipre++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_ipre] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_ipre - 1;

	return (flags);
}

