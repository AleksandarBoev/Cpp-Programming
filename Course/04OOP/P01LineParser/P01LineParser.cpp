#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class LineParser
{
private:
	std::string line;

	bool isNum(const std::string& string)
	{
		for (int i = 0; i < string.length(); i++)
		{
			if (!isdigit(string[i]))
				return false;
		}

		return true;
	}
public:
	LineParser(const std::string& line) :
		line(line)
	{
	}

	int* getNumbers(int& resultingArraySize)
	{
		int counter = 0;
		std::stringstream sStream;
		
	}

	std::string* getStrings(int& resultingArraySize)
	{
		int counter = 0;
	}


};

int main()
{
	std::stringstream stream;
	stream << "1 2 3 4";
	int n1, n2, n3, n4;
	stream >> n1 >> n2 >> n3 >> n4;

	std::cout << n1 << n2 << n3 << n4;


	return 0;
}

