#include "pch.h"
#include <iostream>
#include <string>

/*
Write a program which is given a line of text, another line with a find string and 
another line with a replace string. Any part of text which matches the find string
should be replaced with the replace string. Print the resulting text on the console.

Hint: things like string.find(), string.insert(), string.replace() might be useful

Example input: I am the night. Dark Night! No, not the knightnightday
Example output: I am the day. Dark Night! No, not the kday

Resource with methods: www.cplusplus.com/reference/string/string/replace/
string.replace(startIndexExclusive, endIndexInclusive, replacementString)
*/

void replaceOccurences(std::string& text, const std::string& findString, const std::string& replaceString);

int main()
{
	/*
	std::string wat1 = "Hello, my name is Aleksandar and I will be your guide";
	//					01234567890123456789012345678901234567890123456789012
	//					0		  10		20		  30		40		  50
	std::string replacement = "Aleksandar";
	int replacementStartingIndex = wat1.find(replacement); //18
	int replacementLength = replacement.length();

	wat1.replace(replacementStartingIndex, replacementLength, "Gosho"); //replace from index, number of symbols with
	std::cout << wat1.c_str();
	*/
	std::string text, findString, replaceString;
	std::cout << "Enter your text: ";
	std::getline(std::cin, text);

	std::cout << "Enter the string you want to replace: ";
	std::getline(std::cin, findString);

	std::cout << "Enter the string you want to replace with: ";
	std::getline(std::cin, replaceString);

	replaceOccurences(text, findString, replaceString);
	std::cout << "After replacement the text looks like this:\r\n" << text;

	return 0;
}

void replaceOccurences(std::string& text, const std::string& findString, const std::string& replaceString)
{
	int findStringLength = findString.length();
	while (text.find(findString) != std::string::npos)
	{
		int startingIndex = text.find(findString);
		text.replace(startingIndex, findStringLength, replaceString);
	}
}
