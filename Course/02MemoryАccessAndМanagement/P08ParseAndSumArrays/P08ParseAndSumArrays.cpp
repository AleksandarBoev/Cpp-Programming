#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ArrayParse.h"
#include "ArraySum.h"


/*
Write a function int * parseNumbers(const string& str, int& resultLength)
which returns a pointer to new-allocated array with the numbers parsed from str
(assume you don’t need to handle wrongly-formatted input). str will contain integer
numbers separated by spaces. The function writes the length of the allocated array 
in resultLength. Write a program which lets the user enter a number of lines of integers 
from the console, and prints their sum. Use the parseNumbers function in your program, 
but make sure you delete each array once you’re done with it.

Example input (note: first line is the count of lines of numbers, in this case: 2 lines):
2
1 2
34 5
Expected output (sum of 1 2 3 and 4 5): 15
*/

int main()
{
	int numberOfInputs;
	std::string input;
	std::getline(std::cin, input);
	std::stringstream inputStream(input);
	inputStream >> numberOfInputs;

	int totalSum = 0;
	for (int i = 0; i < numberOfInputs; i++)
	{
		std::string currentLine;
		std::getline(std::cin, currentLine);

		int resultLength = 0;

		int* currentArray = parseNumbers(currentLine, resultLength);
		
		totalSum += getSum(currentArray, resultLength);

		delete[] currentArray;
	}

	std::cout << "The total sum is " << totalSum;

	return 0;
}
