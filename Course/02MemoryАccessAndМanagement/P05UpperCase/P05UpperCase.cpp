#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>

/*
Write a function void makeTitleCase(string& text) which changes each word in text 
to start with a capital letter (don’t bother with the exact title-case rules 
about not capitalizing things like in, from, etc.). Assume the first letter of a 
word is an English alphabetical symbol preceded by a non-alphabetical symbol 
(so in “we will--rock you”, “we”, “will”, “rock” and “you” are all considered
words which need to be capitalized). Call the function from main() with a line of 
text read from the console and then print the modified line of text.

Example input: On the south Carpathian mountains,a tree is swinging
Expected output: On The South Carpathian Mountains,A Tree Is Swinging
*/

void makeTitleCase(std::string& text);

void printLetters(const std::string& text); // www.cplusplus.com/reference/cctype/

int main()
{
	std::string text = "On the south Carpathian mountains,a tree is swinging";
	
	makeTitleCase(text);
	std::cout << text.c_str();

	return 0;
}

void makeTitleCase(std::string& text)
{
	text[0] = toupper(text[0]);

	for (int i = 1; i < text.length(); i++)
	{
		if (!isalpha(text[i - 1]))
			text[i] = toupper(text[i]);
	}
}

void printLetters(const std::string& text)
{
	for (int i = 0; i < text.length(); i++)
	{
		std::cout << "'" << text.at(i) << "' is ";

		isalpha(text.at(i))
			? std::cout << "a letter" << std::endl
			: std::cout << "NOT a letter" << std::endl;
	}
}
