#include "pch.h"
#include <iostream>
#include <math.h>
#include "ReverseDigits.h"

/*
Write a function that reverses the digits of given positive decimal number. 
Example: 256 -> 652
*/

//int getReversedNumber(int number);

int main()
{
	int number;
	std::cin >> number;
	std::cout << getReversedNumber(number);
}

/*
int getReversedNumber(int number)
{
	int result = 0;
	int counter = 0;
	while (number > 0)
	{
		result *= 10;
		result += number % 10;		
		number /= 10;
	}

	return result;
}
*/


