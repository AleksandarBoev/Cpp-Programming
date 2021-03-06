#include "pch.h"
#include <iostream>
#include <string>

/*
Write a program that reads a line from the console containing a mathematical expression.
Write a bool function that checks whether the brackets in the expression () are placed
correctly (assume everything else is correct, i.e. you don’t need to check for correct signs,
correct variables/numbers, etc.) and returns true if they are correct and false if they are not correct

Examples of correctly placed brackets: ((a+b)/5-d); a+b; a+(b); ((a))
Examples of incorrectly placed brackets: ((a+b)/5-d; (a+b; a+b); (a))
*/

bool expressionIsValid(const std::string& expression);

int main()
{
	std::string input;
	std::getline(std::cin, input);

	expressionIsValid(input)
		? std::cout << "Expression is valid!"
		: std::cout << "Expression is NOT valid.";

	return 0;
}

//Instead of copying the string, get the string address and work with the original string.
//Put a const so that you ensure the original string is not changed.
bool expressionIsValid(const std::string& expression) 
{
	int numberOfBrackets = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		char currentLetter = expression.at(i);

		if (currentLetter == '(')
			numberOfBrackets++;
		else if (currentLetter == ')')
		{
			if (--numberOfBrackets < 0)
				return false;
		}
	}

	if (numberOfBrackets == 0)
		return true;
	else
		return false;
}

