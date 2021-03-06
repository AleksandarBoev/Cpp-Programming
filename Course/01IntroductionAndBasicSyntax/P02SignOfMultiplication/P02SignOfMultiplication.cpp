#include "pch.h"
#include <iostream>

/*
Write a program that shows the sign (+ or -) of the product of 
three real numbers without calculating it. Use a sequence of if statements.
*/

int main()
{
	float num1, num2, num3;
	std::cin >> num1 >> num2 >> num3;

	int numberOfNegativeNumbers = 0;

	if (num1 < 0)
		numberOfNegativeNumbers++;

	if (num2 < 0)
		numberOfNegativeNumbers++;

	if (num3 < 0)
		numberOfNegativeNumbers++;

	std::cout << "The product of these three numbers is a ";

	numberOfNegativeNumbers % 2 == 0 ? std::cout << "positive (+)." : std::cout << "negative (-).";

	return 0;
}

