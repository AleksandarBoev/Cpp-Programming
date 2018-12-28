#include "stdafx.h"
#include "ArraySum.h"
int getSum(int* intArray, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += intArray[i];

	return sum;
}