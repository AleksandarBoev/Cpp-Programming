#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

std::vector<int> readArray(const std::string& line);

//inclusive startIndex, explusive endIndex
int getSum(const std::vector<int>& intArray, int startIndex, int endIndex);

//inclusive startIndex, explusive endIndex
int getMin(const std::vector<int>& intArray, int startIndex, int endIndex);

//inclusive startIndex, explusive endIndex
int getMax(const std::vector<int>& intArray, int startIndex, int endIndex);

//inclusive startIndex, explusive endIndex
int getAvg(const std::vector<int>& intArray, int startIndex, int endIndex);

int executeCommand(const std::vector<int>& intArray, int startIndex, int endIndex, int commandType);

int main()
{
	std::string arrayInput;
	std::getline(std::cin, arrayInput);
	std::vector<int> intVector = readArray(arrayInput);

	int numberOfCommandDefinitions;
	std::cin >> numberOfCommandDefinitions;

	std::map<std::string, int> commandNameValue;

	for (int i = 0; i < numberOfCommandDefinitions; i++)
	{
		std::string commandName;
		int commandValue;
		std::cin >> commandName >> commandValue;

		commandNameValue[commandName] = commandValue;
	}

	std::cin.ignore();

	int counter = 0;
	std::string outputString= "{";

	std::string currentLine;
	while (true)
	{
		std::getline(std::cin, currentLine);
		if (currentLine == "end")
			break;

		if (counter > 0)
			outputString.append(",");

		counter++;
		std::stringstream stringStream;
		stringStream << currentLine;

		std::string commandName;
		stringStream >> commandName;

		int startIndex, endIndex;
		stringStream >> startIndex >> endIndex;

		int result = executeCommand(intVector, startIndex, endIndex, commandNameValue[commandName]);

		//TODO program does not work if I use the first stream in the code below
		std::stringstream stringStream2;
		stringStream2 << commandName << "(" << startIndex << "," << endIndex << ")=" << result;

		outputString.append(stringStream2.str());
	}
	outputString.append("}");

	std::cout << "[" << counter << "]" << outputString;

	return 0;
}

std::vector<int> readArray(const std::string& line)
{
	std::stringstream stringStream;
	stringStream << line;

	std::vector<int> intVector;
	int currentValue;
	while (stringStream >> currentValue)
	{
		intVector.push_back(currentValue);
	}

	return intVector;
}

int getSum(const std::vector<int>& intArray, int startIndex, int endIndex)
{
	int sum = 0;
	for (int i = startIndex; i < endIndex; i++)
		sum += intArray[i];

	return sum;
}

int getMin(const std::vector<int>& intArray, int startIndex, int endIndex)
{
	int min = intArray[startIndex];

	for (int i = startIndex + 1; i < endIndex; i++)
	{
		if (intArray[i] < min)
			min = intArray[i];
	}

	return min;
}

int getMax(const std::vector<int>& intArray, int startIndex, int endIndex)
{
	int max = intArray[startIndex];

	for (int i = startIndex + 1; i < endIndex; i++)
	{
		if (intArray[i] > max)
			max = intArray[i];
	}

	return max;
}

int getAvg(const std::vector<int>& intArray, int startIndex, int endIndex)
{
	int sum = getSum(intArray, startIndex, endIndex);
	int numberOfElements = endIndex - startIndex;

	double average = sum / (double)numberOfElements;

	return (int)average;
}

int executeCommand(const std::vector<int>& intArray, int startIndex, int endIndex, int commandType)
{
	switch (commandType)
	{
	case 0:
		return getSum(intArray, startIndex, endIndex);

	case 1:
		return getAvg(intArray, startIndex, endIndex);

	case 2:
		return getMin(intArray, startIndex, endIndex);

	case 3:
		return getMax(intArray, startIndex, endIndex);

	default:
		return -1;
	}
}

