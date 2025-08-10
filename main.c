// FinalProject_CPR101_NCC_GRP4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "converting.h"
#include "tokenizing.h"
#include "fundamentals.h"
#include "manipulating.h"

int main()
{
	char buffer[100]; // Buffer to hold user input
	do
	{
		printf("which module to run?\n\n");
		printf("1. Fundametals\n");
		printf("2. Manipulating\n");
		printf("3. Converting\n");
		printf("4. Tokenizing\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		fgets(buffer, sizeof(buffer), stdin); // Read user input
		switch (buffer[0])					  // Check the first character of the input
		{
		case '1':
			fundamentals(); // Call the fundamentals module
			break;
		case '2':
			manipulating(); // Call the manipulating module
			break;
		case '3':
			converting(); // Call the converting module
			break;
		case '4':
			tokenizing(); // Call the tokenizing module
			break;
		case '0':
			printf("------------exiting the program------------");
			break;
		default:
			printf("Invalid option. Please try again.\n"); // Handle invalid input
		}
	} while (buffer[0] != '0'); // Continue until user chooses to exit

	return 0; // Exit the program
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
