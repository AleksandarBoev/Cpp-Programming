#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

std::string getEnglishGreeting(std::string name);

std::string getBulgarianGreeting(std::string name);

std::string getJapaneseGreeting(std::string name);

std::string greeting(std::string (*someGreeting)(std::string name), std::string name);

int main()
{
	std::cout << greeting(&getBulgarianGreeting, "Aleksandar") << std::endl;

	std::string(*someFunction)(std::string wat) = &getEnglishGreeting;

	std::cout << someFunction("Sasho") << std::endl;

	return 0;
}


std::string getEnglishGreeting(std::string name)
{
	return "Hello, " + name;
}

std::string getBulgarianGreeting(std::string name)
{
	return "Zdravei, " + name;
}

std::string getJapaneseGreeting(std::string name)
{
	return "Kornichiua, " + name;
}

std::string greeting(std::string(*someGreeting)(std::string name), std::string name)
{
	return "The greeting I have coded will look like this:\r\n" + (*someGreeting)(name);
}

