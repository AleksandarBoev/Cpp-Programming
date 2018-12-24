

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::cout << "Enter a grade: ";
	double grade;
	std::cin >> grade;

	if (grade >= 5.50 && grade <= 6.00) // OR = ||
	{
		std::cout << "Excellent!";
	}
	else if (grade >= 4.50 && grade < 5.50)
	{
		std::cout << "Very good!";
	}
	else if (grade >= 3.50 && grade < 4.50)
	{
		std::cout << "Meh";
	}
	else
	{
		std::cout << "Try again";
	}
	std::cout << std::endl;

	std::cout << "Enter a number from 1 to 3: ";
	int number;
	std::cin >> number;
	std::string numberName;

	switch (number) //works only with primitive types(int, char, enum). Needs a big workaround for strings
	{
	case 1:
		numberName = "one";
		break;

	case 2:
		numberName = "two";
		break;

	case 3:
		numberName = "three";
		break;

	default:
		numberName = "cheeky, aren't we";
		break;
	}
	std::cout << numberName;

	return 0;
}

