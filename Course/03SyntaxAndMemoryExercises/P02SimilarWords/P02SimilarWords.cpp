#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

double calculatePercentageMatch(const std::string& word1, const std::string& word2);

int getMatchingLettersCount(const std::string& text, const::std::string& word, int matchingPercent);

void replaceAllNonAlphaSymbolsWithSpaces(std::string& text);

int main()
{
	std::string text, word;
	int percentage;

	std::getline(std::cin, text);
	std::cin >> word >> percentage;
	
	std::cout << getMatchingLettersCount(text, word, percentage);

	return 0;
}

double calculatePercentageMatch(const std::string& word1, const std::string& word2)
{
	if (word1.length() != word2.length())
		return 0;

	int matchingLetters = 0;

	for (int i = 0; i < word1.length(); i++)
	{
		if (word1[i] == word2[i])
			matchingLetters++;
	}

	return matchingLetters / (double)word1.length() * 100;
}

//Here is, the money.. of !the-concatentation;
int getMatchingLettersCount(const std::string& text, const::std::string& word, int matchingPercent)
{
	std::string processedText = text;
	replaceAllNonAlphaSymbolsWithSpaces(processedText);

	std::stringstream stringStream;
	stringStream << processedText;

	int counter = 0;
	std::string currentWord;
	while (stringStream >> currentWord)
	{
		if (calculatePercentageMatch(currentWord, word) > matchingPercent)
			counter++;
	}

	return counter;
}

void replaceAllNonAlphaSymbolsWithSpaces(std::string& text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (!isalpha(text[i]))
			text[i] = ' ';
	}
}