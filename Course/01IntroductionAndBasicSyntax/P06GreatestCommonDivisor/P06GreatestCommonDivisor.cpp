#include "pch.h"
#include <iostream>

/*
Write a program that calculates the greatest common divisor (GCD) of given two numbers. 
Use the Euclidean algorithm (find it in Internet)
*/

int main()
{
    std::cout << "Divident: ";
	int divident;
	std::cin >> divident;

	std::cout << "Divisor: ";
	int divisor;
	std::cin >> divisor;

	int remainder;

	while ((remainder = divident % divisor) != 0)
	{
		divident = divisor;
		divisor = remainder;
	}

	std::cout << "GCD is " <<divisor;

	return 0;
}


