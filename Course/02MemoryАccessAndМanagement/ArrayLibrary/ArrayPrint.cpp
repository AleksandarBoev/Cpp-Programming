#include "stdafx.h"
#include <iostream>
#include "ArrayPrint.h"

void basicPrint(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << std::endl;
	}
}

void prettyPrint(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}
