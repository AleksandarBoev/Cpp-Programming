#include "pch.h"
#include <iostream>
#include <string>

/*
Write a function int occurences(const string& text, const string& search) 
which returns the number of times search is contained in text.

Example call: string text = “Write a function int occurences(const string& text, const string& search)
which returns the number of times search is contained in text”string search = “on”;
occurences(text, search);
Expected result: 4
Make a program which reads two lines of text from the console – first the text,
then the search string and prints the number of times search is contained in text
*/

int occurences(const std::string& text, const std::string& search);

int main()
{
	/*
	std::string text;
	text.append("Write a function int occurences(const string& text, const string& search)");
	text.append("which returns the number of times search is contained in text");

	std::cout << occurences(text, "on"); //4
	*/
	std::string inputText, inputSearch;
	std::getline(std::cin, inputText);
	std::getline(std::cin, inputSearch);

	std::cout << occurences(inputText, inputSearch);

	return 0;
}

int occurences(const std::string& text, const std::string& search)
{
	int count = 0;
	int lastIndexFound = 0;
	//4294967295
	while (text.find(search, lastIndexFound) != std::string::npos)
	{
		lastIndexFound = text.find(search, lastIndexFound) + 10;
		count++;
	}

	return count;
}