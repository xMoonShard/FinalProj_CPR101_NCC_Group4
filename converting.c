#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "converting.h"

// Function prototypes for string to integer conversion
int atoi1(const char *str)
{

	int result = 0;
	int sign = 1;

	while (*str == ' ')
	{
		str++;
	}

	// Check for sign
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	// Convert string to integer
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return sign * result;
}

int atof1(const char *str)
{

	double result = 0.0;
	double factor = 1.0;
	int sign = 1;

	// Skip whitespace
	while (*str == ' ')
	{
		str++;
	}
	// Check for sign
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	// Convert integer part
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	// Check for decimal point
	if (*str == '.')
	{
		str++;
	}
	// Convert fractional part
	while (*str >= '0' && *str <= '9')
	{
		factor /= 10.0;
		result += (*str - '0') * factor;
		str++;
	}
	return sign * result;
}

int converting(void)
{
	char str[101];

	// Prompt user for input
	printf("Enter a string to convert to integer, double, and long: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

	// Call the conversion functions
	printf("and the integer: %d\n", atoi1(str));
	printf("The double: %.2f\n", atof1(str));

	return 0;
}