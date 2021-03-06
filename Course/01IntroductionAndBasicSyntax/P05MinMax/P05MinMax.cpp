#include "pch.h"
#include <iostream>

/*
Write a program that reads from the console a sequence of N integer numbers 
and returns the minimal and maximal of them
*/

int main()
{
	int n;
	std::cin >> n;

	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		int currentNumber;
		std::cin >> currentNumber;

		if (currentNumber < min)
			min = currentNumber;

		if (currentNumber > max)
			max = currentNumber;
	}

	std::cout << "Smallest number is " << min << ", and biggest one is " << max;
	return 0;
}

