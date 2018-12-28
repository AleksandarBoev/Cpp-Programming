#include "pch.h"
#include "CompareArrays.h"

bool compareArrays(int array1[], int length1, int array2[], int length2)
{
	if (length1 != length2)
		return false;

	bool areEqual = true;

	for (int i = 0; i < length1; i++)
	{
		if (array1[i] != array2[i])
		{
			areEqual = false;
			break;
		}
	}

	return areEqual;
}