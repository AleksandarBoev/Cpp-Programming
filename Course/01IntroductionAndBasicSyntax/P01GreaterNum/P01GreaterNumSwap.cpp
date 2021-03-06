#include "pch.h"
#include <iostream>

/*
Write a conditional statement that examines two integer variables and 
exchanges their values if the first one is greater than the second one.
*/

int main()
{
    std::cout << "Number1: ";
	signed long int num1; //signed, long are not needed, but this is what int actually looks like
	std::cin >> num1;

	std::cout << "Number2: ";
	signed long int num2;
	std::cin >> num2;

	if (num1 > num2)
	{
		num2 += num1;
		num1 = num2 - num1;
		num2 -= num1;
	}

	std::cout << "Num1 current value is: " << num1 << std::endl;
	std::cout << "Num2 current value is: " << num2 << std::endl;

	return 0;
}

