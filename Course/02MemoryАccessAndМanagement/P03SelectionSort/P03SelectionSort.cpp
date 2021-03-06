#include "pch.h"
#include <iostream>
#include <sstream>
#include "ArrayPrint.h"

/*
Write a void selectionSort(int a[], int start, int end) function that 
uses the selection sort algorithm to sort the elements 
from arr[start] to arr[end – 1] in increasing order 
the elements outside the [start, end) range shouldn’t be sorted). 
This function modifies the array, so that the elements between start and end are sorted.

Selection sort: in this case it would just find the smallest 
element between start and end, and place it at the start, then 
find the next smallest between the remaining (aka start + 1 and end) 
and place it at the next position (aka start + 1) and so on
*/
void selectionSort(int array[], int start, int end);

void swapIntegerValues(int& integer1, int& integer2)
{
	int temp = integer1;

	integer1 = integer2;
	integer2 = temp;
}

int main()
{
	int* array = new int[5]{9, 3, 2, 1, 10};
	selectionSort(array, 1, 4);

	prettyPrint(array, 5);
	delete[] array;

	return 0;
}


void selectionSort(int array[], int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int min = array[i];
		int minIndex = i;

		for (int j = i + 1; j < end; j++)
		{
			if (array[j] < min)
			{
				minIndex = j;
				min = array[j];
			}
		}

		if (i != minIndex)
		{
			swapIntegerValues(array[i], array[minIndex]);
		}
	}
}
