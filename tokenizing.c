#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "tokenizing.h"
#define _MAX_STRING_LENGTH 100

void strtok1(const char *inputstr)
{
	int i = 0;
	while (1)
	{
		char testing[_MAX_STRING_LENGTH], *t = testing;
		while (inputstr[i] && (inputstr[i] != ' '))
		{
			*t++ = inputstr[i++];
		}
		if (t > testing)
		{
			*t = '\0';
			printf("%s\n", testing);
		}
		if (!inputstr[i])
		{
			break;
		}
		i++; // Skip the space character
	}
}

void strtok2(const char *inputstr, const char *delim)
{
	int i = 0;
	while (1)
	{
		char testing[_MAX_STRING_LENGTH], *t = testing;
		while (inputstr[i] && (strchr(delim, inputstr[i]) == NULL))
		{
			*t++ = inputstr[i++];
		}
		if (t > testing)
		{
			*t = '\0';
			printf("%s\n", testing);
		}
		if (!inputstr[i])
		{
			break;
		}
		i++; // Skip the delimiter character
	}
}

void tokenizing(void)
{
	char str[_MAX_STRING_LENGTH]; // Assuming a maximum length for the string

	printf("Enter a string to tokenize: ");

	fgets(str, _MAX_STRING_LENGTH, stdin);
	str[strcspn(str, "\n")] = '\0'; // remove newline

	strtok1(str);
	strtok2(str, ","); // Example delimiters

	printf("Tokenization complete.\n");
}