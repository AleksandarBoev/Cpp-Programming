#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ArraySum.h"
#include "ArrayParse.h"

/*
Write a program which does the same as task 8, but instead of printing to the console, 
asks the user for the name of an input file and an output file 
(each entered on a separate line) and reads the input from the input file 
and prints the output in the output file. If the output file already exists, 
it should be overwritten. Note: the input and output file could be the same.

Note2: just copy-paste the code from 8 to reuse it
*/

int main()
{
	std::string inputFilePath, outputFilePath;
	std::cout << "Input file path: ";
	std::getline(std::cin, inputFilePath); //type in "15-input.txt"

	std::cout << "Output file path: ";
	std::getline(std::cin, outputFilePath); //type in "15-output.txt"

	std::ifstream inputFileStream(inputFilePath);

	int sum = 0;

	std::string currentLine;
	while (std::getline(inputFileStream, currentLine))
	{
		int currentArrayLength;
		int* currentArray = parseNumbers(currentLine, currentArrayLength);

		sum += getSum(currentArray, currentArrayLength);

		delete[] currentArray;
	}
	inputFileStream.close();

	std::ofstream outputFileStream(outputFilePath);
	outputFileStream << "The sum is: " << sum;
	outputFileStream.close();

	return 0;
}

