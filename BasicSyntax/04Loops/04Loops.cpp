#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	bool aBool = true;
	std::cout << aBool << std::endl; //1

	aBool = !aBool;
	std::cout << aBool << std::endl; //0

	//Reading a string would give a 0(false) (even if its "true"/"True"). 
	//Reading an int, different than 0 would result in 1 (true)
	std::cin >> aBool;
	std::cout << aBool << std::endl;

	char w = 'a';
	std::cout << w << std::endl; //"a"

	std::string word = "Cloud";
	for (int i = 0; i < word.length(); i++)
	{
		putchar(word[i]); //not exactly sure what it does. Maybe adds the char to the output string
		putchar(' ');
	}
	std::cout << std::endl; //"C l o u d"

	int counter = 0;
	while (word != "end")
	{
		std::cout << ++counter << std::endl;
		std::cin >> word;
	}

	do
	{
		std::cout << --counter << std::endl;
		std::cin >> word;
	} while (word != "stop");

	return 0;
}

