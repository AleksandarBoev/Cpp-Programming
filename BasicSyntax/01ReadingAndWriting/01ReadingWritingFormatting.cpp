// 01ReadingAndWriting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h" //just needed. And also it HAS to be the first of the included stuff, otherwise errors will show up
#include <iostream> //needed for reading and writing
#include <string>
#include <sstream>

int main()
{
	std::cout << "Enter a word: "; //if there was an "std::endl" then the cursor would be on a new line
	std::string word;
	std::getline(std::cin, word); 
	//if only 'std::cin >> word;' was the code and "This is a sentence" was entered, this problem would occur:
	//"This" is the value of word. " is a sentence" is the value of the line. Does not wait for another imput,
	//just reads both string values at once.
	std::cout << "The word you just entered is " << word << std::endl; //better way I think
	std::cout << "Another way of contatinating strings is like this " + word << std::endl;

	std::string line;
	std::cout << "Now enter a sentence: ";
	std::getline(std::cin, line); //if 'Hello World' is entered, then it is read properly
	//formatting like this is slower than using '<< ... << ... << ...'
	std::printf("The sentence you just entered is '%s'\r\n and this message is a formatted print\r\n", 
		line.c_str()); //writing '.c_str()', because output is some strange symbols if not added
	//\r\n is a new line inside a string. It's better than just \n, because it works on more OSs

	
	double num1;

	std::string input;
	//std::getline(std::cin, input);
	input = "3.99";

	//this is needed to work: #include <sstream>
	std::stringstream someStream(input);
	someStream >> num1; //something like Double.parseDouble("3.99")

	std::cout << num1;
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
