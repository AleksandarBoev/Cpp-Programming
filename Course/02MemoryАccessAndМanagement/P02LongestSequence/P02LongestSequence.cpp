#include "pch.h"
#include <iostream>

/*
Write a program that finds the longest sequence of equal elements in an 
integer array and then prints that sequence on the console (integers separated by space or newline)
*/

int longestSequence(int array[], int length);

int main()
{
	int length;
	std::cin >> length;

	int* intArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		std::cout << "array[" << i << "] = ";
		std::cin >> intArray[i];
	}

	std::cout << longestSequence(intArray, length);
	delete[] intArray;

	return 0;
}

int longestSequence(int array[], int length)
{
	int maxSequence = 1;
	int currentSequence = 1;
	int lastNumber = array[0];

	for (int i = 1; i < length; i++)
	{
		if (lastNumber != array[i])
		{
			lastNumber = array[i];
			if (maxSequence < currentSequence)
				maxSequence = currentSequence;

			currentSequence = 1;
		}
		else
		{
			currentSequence++;
		}
	}

	if (maxSequence < currentSequence)
		maxSequence = currentSequence;

	return maxSequence;
}