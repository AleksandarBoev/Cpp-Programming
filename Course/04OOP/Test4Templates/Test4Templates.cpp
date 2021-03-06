#include "pch.h"
#include <iostream>

template<typename T>
void swapValues(T &param1, T &param2);

template<typename T1, typename T2>
void printResults(T1 param1, T1 param2, T2 param3, T2 param4);

int main()
{
	double doubleNum1 = 5.0, doubleNum2 = 3.0;
	int intNum1 = 44, intNum2 = 66;

	printResults(doubleNum1, doubleNum2, intNum1, intNum2);

	swapValues(doubleNum1, doubleNum2);
	swapValues(intNum1, intNum2);

	printResults(doubleNum1, doubleNum2, intNum1, intNum2); //values swaped successfuly.

	return 0;
}

template<typename T>
void swapValues(T &param1, T &param2)
{
	T swap = param1;
	param1 = param2;
	param2 = swap;
}

template<typename T1, typename T2>
void printResults(T1 param1, T1 param2, T2 param3, T2 param4)
{
	std::cout << "Value of doubleNum1 = " << param1 << " and of doubleNum2 = " << param2 << std::endl
		 << "Value of intNum1 = " << param3 << " and of intNum2 = " << param4 << std::endl;
}

