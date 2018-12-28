#include "stdafx.h"
#include "ArrayParse.h"
#include <vector>
#include <sstream>

int* parseNumbers(const std::string& str, int& resultLength)
{
	std::vector<int> vector;
	std::istringstream strStream(str);

	int currentNum;
	while (strStream >> currentNum)
		vector.push_back(currentNum);

	resultLength = vector.size();
	int* resultArray = new int[resultLength];

	for (int i = 0; i < resultLength; i++)
	{
		resultArray[i] = vector[i];
	}

	return resultArray;
}